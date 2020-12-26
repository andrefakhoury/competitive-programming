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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int a[MAXN];
int n;
int seg[4 * MAXN][4]; // xor, and, or, max

inline void merge(int p) {
	seg[p][0] = seg[p+p][0] ^ seg[p+p+1][0];
	seg[p][1] = seg[p+p][1] & seg[p+p+1][1];
	seg[p][2] = seg[p+p][2] | seg[p+p+1][2];
	seg[p][3] = max(seg[p+p][3], seg[p+p+1][3]);
}

void build(int p, int i, int j) {
	if (i == j) {
		for (int k = 0; k < 4; k++) {
			seg[p][k] = a[i];
		}
	} else {
		int m = (i + j) / 2;
		build(p+p, i, m);
		build(p+p+1, m+1, j);
		merge(p);
	}
}

void update(int p, int i, int j, int k, int v) {
	if (i == j) {
		for (int xx = 0; xx < 4; xx++) seg[p][xx] = v;
	} else {
		int m = (i + j) / 2;
		if (m >= k) update(p+p, i, m, k, v);
		else update(p+p+1, m+1, j, k, v);
		merge(p);
	}
}

void update(int k, int v) {
	update(1, 1, n, k, v);
}

int query(int p, int i, int j, int l, int r, int idx) {
	if (i >= l && j <= r) return seg[p][idx];
	else if (i > r or j < l) return -INF;

	int m = (i + j) / 2;
	int ans1 = query(p+p, i, m, l, r, idx);
	int ans2 = query(p+p+1, m+1, j, l, r, idx);

	if (ans1 < 0) return ans2;
	if (ans2 < 0) return ans1;

	if (idx == 0) return ans1^ans2;
	if (idx == 1) return ans1&ans2;
	if (idx == 2) return ans1|ans2;
	return max(ans1, ans2);
}

int query(int l, int r, int idx) {
	if (l > r) {
		if (idx == 0) return 0;
		if (idx == 1) return 2147483647;
		if (idx == 2) return 0;
		return -1;
	}
	return query(1, 1, n, l, r, idx);
}

int main() {
	int q; rd(n, q);

	map<int, set<int>> mp;

	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		mp[a[i]].emplace(i);
	}

	build(1, 1, n);

	while(q--) {
		char op; scanf(" %c", &op);
		int l, r; rd(l, r);

		if (op == 'x') {
			int xx = query(l, r, 0);
			if (xx == 0) {
				printf("%d\n", query(l, r, 3));
			} else printf("-1\n");
		} else if (op == 'a') {
			int xx = query(l, r, 1);
			auto it = mp[xx].lower_bound(l);
			if (it != mp[xx].end() && *it <= r) {
				int cur = *it;
				if ((query(l, cur-1, 1)&query(cur+1, r, 1)) != xx)
					xx = -1;
				printf("%d\n", xx);
			} else printf("-1\n");
		} else if (op == 'o') {
			int xx = query(l, r, 2);
			auto it = mp[xx].lower_bound(l);
			if (it != mp[xx].end() && *it <= r) {
				int cur = *it;
				if ((query(l, cur-1, 2)|query(cur+1, r, 2)) != xx)
					xx = -1;

				printf("%d\n", xx);
			} else printf("-1\n");
		} else {
			mp[a[l]].erase(l);
			a[l] = r;
			update(l, r);
			mp[a[l]].emplace(l);
		}
	}
}