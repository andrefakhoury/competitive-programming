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

int c[MAXN];
int sz[MAXN];
int level[MAXN];
int par[MAXN][21];
int pos[MAXN];
int cur_time;
int cur_chain = 1;
int chain[MAXN];
vector<int> same[MAXN];
vector<int> edges[MAXN];
int euler[MAXN];
ll seg[4 * MAXN];

void build(int p, int i, int j) {
	if (i == j) seg[p] = 1ll << c[euler[i]];
	else {
		int m = (i + j) / 2;
		build(p+p, i, m);
		build(p+p+1, m+1, j);
		seg[p] = seg[p+p] | seg[p+p+1];
	}
}

void update(int p, int i, int j, int k, int v) {
	if (i == j) seg[p] = 1ll << v;
	else {
		int m = (i + j) / 2;
		if (m >= k) update(p+p, i, m, k, v);
		else update(p+p+1, m+1, j, k, v);
		seg[p] = seg[p+p] | seg[p+p+1];
	}
}

void update(int k, int v) {
	update(1, 1, MAXN-1, k, v);
}

ll query(int p, int i, int j, int l, int r) {
	if (i >= l && j <= r) return seg[p];
	else if (i > r or j < l) return 0;

	int m = (i + j) / 2;
	ll ans = query(p+p, i, m, l, r);
	ans = ans | query(p+p+1, m+1, j, l, r);
	return ans;
}

ll query(int l, int r) {
	return query(1, 1, MAXN-1, l, r);
}

int dfs_init(int u, int p = -1) {
	sz[u] = 1;
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		par[v][0] = u;
		sz[v] += dfs_init(v, u);
	}
	return sz[u];
}

void dfs_euler(int u, int p = -1, int ch = 1) {
	pos[u] = ++cur_time;
	euler[cur_time] = u;
	chain[u] = ch;
	same[ch].eb(u);

	int heavy = -1;
	for (int v : edges[u]) if (v != p) {
		if (heavy == -1 or sz[heavy] < sz[v])
			heavy = v;
	}

	if (heavy != -1) dfs_euler(heavy, u, ch);

	for (int v : edges[u]) if (v != p && v != heavy)
		dfs_euler(v, u, ++cur_chain);
}

inline ll getans(int u, int v) {
	ll ans = 0;
	while(chain[u] != chain[v]) {
		int l = same[chain[u]].front();
		ans = ans | query(pos[l], pos[u]);
		u = par[l][0];
	}

	ans = ans | query(pos[v], pos[u]);
	return ans;
}

inline int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
 
	for (int i = 20; i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
			u = par[u][i];
 
	if (u == v) return u;
 
	for (int i = 20; i >= 0; i--) {
		if (par[u][i] != par[v][i]) { 
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

int main() {
	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(c[i]);

	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	dfs_init(1);

	for (int b = 1; b <= 20; b++) {
		for (int u = 1; u <= n; u++) {
			par[u][b] = par[par[u][b-1]][b-1];
		}
	}

	dfs_euler(1);
	build(1, 1, MAXN-1);

	int q; rd(q);
	while(q--) {
		int op, u, v; rd(op, u, v);
		if (op == 1) {
			update(pos[u], v);
		} else {
			int l = lca(u, v);
			ll ans = getans(u, l) | getans(v, l);
			ans = __builtin_popcountll(ans);
			printf("%lld\n", ans);
		}
	}

}