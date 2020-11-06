#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }


const int MAXN = 1e3 + 5;

int a[MAXN][MAXN]; // initial matrix. Will be used on Seg2D::build

struct Seg2D {
	struct Node {
		int val = 0;
		template<typename T>
		Node(T val) : val(val) {}

		Node() {}
		void init(Node const& l, Node const& r) {
			val = max(l.val, r.val);
		}
	};

	int n, m;
	vector<vector<Node>> seg;

	Seg2D(int n, int m) : n(n), m(m) { // size of each dimension must be 2^(1 + ceil(log2 n)). Be careful with MLE
		int qn = 33 - __builtin_clz(n - 1);
		int qm = 33 - __builtin_clz(m - 1);
		seg = vector<vector<Node>>(1 << qn, vector<Node>(1 << qm));
	}

	void buildY(int px, int xi, int xj, int py, int yi, int yj) {
		if (yi == yj) {
			if (xi == xj) seg[px][py] = a[xi][yi];
			else seg[px][py].init(seg[px+px][py], seg[px+px+1][py]);
		} else {
			int mi = (yi + yj) / 2;
			buildY(px, xi, xj, py + py, yi, mi);
			buildY(px, xi, xj, py + py + 1, mi + 1, yj);
			seg[px][py].init(seg[px][py+py], seg[px][py+py+1]);
		}
	}

	void buildX(int p, int i, int j) {
		if (i != j) {
			int mi = (i + j) / 2;
			buildX(p + p, i, mi);
			buildX(p + p + 1, mi + 1, j);
		}
		buildY(p, i, j, 1, 1, m);
	}

	void build() {
		buildX(1, 1, n);
	}

	void updateY(int px, int xi, int xj, int py, int yi, int yj, int y, int val) {
		if (yi == yj) {
			if (xi == xj) seg[px][py] = val;
			else seg[px][py].init(seg[px+px][py], seg[px+px+1][py]);
		} else {
			int mi = (yi + yj) / 2;
			if (y <= mi) updateY(px, xi, xj, py + py, yi, mi, y, val);
			else updateY(px, xi, xj, py + py + 1, mi + 1, yj, y, val);
			seg[px][py].init(seg[px][py+py], seg[px][py+py+1]);
		}
	}

	void updateX(int p, int i, int j, int x, int y, int val) {
		if (i != j) {
			int mi = (i + j) / 2;
			if (x <= mi) updateX(p + p, i, mi, x, y, val);
			else updateX(p + p + 1, mi + 1, j, x, y, val);
		}
		updateY(p, i, j, 1, 1, m, y, val);
	}

	void update(int x, int y, int val) {
		updateX(1, 1, n, x, y, val);
	}

	Node queryY(int px, int py, int i, int j, int l, int r) {
		if (i >= l && j <= r) return seg[px][py];
		int mi = (i + j) / 2;
		if (mi >= r) return queryY(px, py+py, i, mi, l, r);
		else if (mi < l) return queryY(px, py+py+1, mi+1, j, l, r);
		Node ans;
		Node L = queryY(px, py+py, i, mi, l, r);
		Node R = queryY(px, py+py+1, mi+1, j, l, r);
		ans.init(L, R);
		return ans;
	}

	Node queryX(int p, int i, int j, int lx, int ly, int rx, int ry) {
		if (i < lx || j > rx) {
			int mi = (i + j) / 2;
			if (mi >= rx) return queryX(p+p, i, mi, lx, ly, rx, ry);
			else if (mi < lx) return queryX(p+p+1, mi+1, j, lx, ly, rx, ry);
			Node ans;
			Node L = queryX(p+p, i, mi, lx, ly, rx, ry);
			Node R = queryX(p+p+1, mi+1, j, lx, ly, rx, ry);
			ans.init(L, R);
			return ans;
		}
		return queryY(p, 1, 1, m, ly, ry);
	}

	Node query(int lx, int ly, int rx, int ry) {
		return queryX(1, 1, n, lx, ly, rx, ry);
	}
};

int main() {
	int n; rd(n);

	Seg2D seg(1e3, 1e3);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y; rd(x, y);
		int b = seg.query(1, 1, x, y).val + 1;
		ans = max(ans, b);
		seg.update(x, y, b);
	}

	printf("%d\n", ans);
}
