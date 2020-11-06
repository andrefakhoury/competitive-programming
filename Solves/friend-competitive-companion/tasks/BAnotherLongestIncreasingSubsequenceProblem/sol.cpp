#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx")

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

struct Seg2D_D {  // external SegTree
	struct Node { // internal SegTree
		Node *L, *R;
		int answer;
		int i, j;

		Node(int i, int j) : L(nullptr), R(nullptr), answer(0), i(i), j(j) { }
		Node() : L(nullptr), R(nullptr), answer(0) { }
		Node(int ans) : L(nullptr), R(nullptr), answer(ans) {}

		void apply(Node *l, Node* r);
		void update(Node* nxL, Node* nxR, int y, int val);
		Node query(int l, int r);
	} *root;

	Seg2D_D *L, *R;
	int i, j; // interval that it's responsible
	int yi, yj;  // complete interval of Y axis

	Seg2D_D() = default;
	Seg2D_D(int i, int j, int yi, int yj);
	void update(int x, int y, int val);
	Node query(int lx, int ly, int rx, int ry);
};

const Seg2D_D::Node emptyNode;
const int SEG_MAX = 270000;
const int NODE_MAX = 30000000;

int curSegDB;
Seg2D_D segDB[SEG_MAX];
int curNodeDB;
Seg2D_D::Node nodeDB[NODE_MAX];

Seg2D_D::Seg2D_D(int i, int j, int yi, int yj) : i(i), j(j), yi(yi), yj(yj) {
	L = R = nullptr;
	root = new (&nodeDB[curNodeDB++]) Node(yi, yj);
}

void Seg2D_D::update(int x, int y, int val) {
	if (i != j) {
		if (x <= (i+j)/2) {
			if (L == nullptr) L = new (&segDB[curSegDB++]) Seg2D_D(i, (i+j)/2, yi, yj);
			L->update(x, y, val);
		} else {
			if (R == nullptr) R = new (&segDB[curSegDB++]) Seg2D_D((i+j)/2+1, j, yi, yj);
			R->update(x, y, val);
		}
	}

	root->update(L == nullptr ? nullptr : L->root,
				 R == nullptr ? nullptr : R->root, y, val);
}

Seg2D_D::Node Seg2D_D::query(int lx, int ly, int rx, int ry) {
	if (i < lx || j > rx) {
		if ((i+j)/2 >= rx) return L == nullptr ? emptyNode : L->query(lx, ly, rx, ry);
		else if ((i+j)/2 < lx) return R == nullptr ? emptyNode : R->query(lx, ly, rx, ry);
		Node ans, ln, rn;
		ln = L == nullptr ? ln : L->query(lx, ly, rx, ry);
		rn = R == nullptr ? rn : R->query(lx, ly, rx, ry);
		ans.apply(&ln, &rn);
		return ans;
	}
	return root->query(ly, ry);
}

void Seg2D_D::Node::apply(Node *l, Node* r) {
	if (l == nullptr) swap(l, r);
	if (l == nullptr) return;
	else if (r == nullptr) answer = l->answer;
	else answer = max(l->answer, r->answer);
}

void Seg2D_D::Node::update(Node* nxL, Node* nxR, int y, int val) {
	if (i == j) {
		if (nxL == nullptr && nxR == nullptr) answer = val;
		else apply(nxL, nxR);
	} else {
		if (y <= (i+j)/2) {
			if (L == nullptr) L = new (&nodeDB[curNodeDB++]) Node(i, (i+j)/2);
			L->update(nxL == nullptr ? nullptr : nxL->L,
					  nxR == nullptr ? nullptr : nxR->L, y, val);
		} else {
			if (R == nullptr) R = new (&nodeDB[curNodeDB++]) Node((i+j)/2+1, j);
			R->update(nxL == nullptr ? nullptr : nxL->R,
					  nxR == nullptr ? nullptr : nxR->R, y, val);
		}
		apply(L, R);
	}
}

Seg2D_D::Node Seg2D_D::Node::query(int l, int r) {
	if (i >= l && j <= r) return Node(answer);
	if ((i+j)/2 >= r) return L == nullptr ? emptyNode : L->query(l, r);
	if ((i+j)/2 < l)  return R == nullptr ? emptyNode : R->query(l, r);
	Node ans, ln, rn;
	ln = L == nullptr ? ln : L->query(l, r);
	rn = R == nullptr ? rn : R->query(l, r);
	ans.apply(&ln, &rn);
	return ans;
}

const int MAXN = 1e5;
int allx[MAXN];
int ally[MAXN];
pii a[MAXN];

int main() {
	int n; rd(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
		allx[i] = a[i].fi;
		ally[i] = a[i].se;
	}

	sort(allx, allx+n);
	sort(ally, ally+n);
	int nx = unique(allx, allx+n) - allx;
	int ny = unique(ally, ally+n) - ally;

	Seg2D_D seg(0, nx-1, 0, ny-1);

	int ret = 0, x, y, cur;
	for (int i = 0; i < n; i++) {
		x = lower_bound(allx, allx+nx, a[i].fi) - allx;
		y = lower_bound(ally, ally+ny, a[i].se) - ally;
		cur = x && y ? seg.query(0, 0, x - 1, y - 1).answer + 1 : 1;
		ret = max(ret, cur);
		seg.update(x, y, cur);
	}

	printf("%d\n", ret);
}
