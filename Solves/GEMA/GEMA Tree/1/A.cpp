#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	// #define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;
const int MAXL = 21;

vector<pii> edges[MAXN];
int weight[MAXN];
int sz[MAXN];
int level[MAXN];
int par[MAXN][MAXL];
int euler[MAXN];
int pos[MAXN];
int who[MAXN];
int cur_time;
int cur_chain;
int chain[MAXN];
int ini[MAXN];
int pai[MAXN];
vector<int> same[MAXN];

struct Seg {
	int seg[4 * MAXN];

	void build(int p, int i, int j) {
		if (i == j) seg[p] = euler[i];
		else {
			int m = (i + j) / 2;
			build(p+p, i, m);
			build(p+p+1, m+1, j);
			seg[p] = max(seg[p+p], seg[p+p+1]);
		}
	}

	inline void init() {
		build(1, 1, MAXN-1);
	}

	int query(int p, int i, int j, int l, int r, int x) {
		if (i > j || i > r || j < l) return 0;
		if (i >= l && j <= r) {
			if (~x) seg[p] = x;
			return seg[p];
		} else {
			int m = (i + j) / 2;
			int L = query(p+p, i, m, l, r, x);
			int R = query(p+p+1, m+1, j, l, r, x);
			seg[p] = max(seg[p+p], seg[p+p+1]);
			return max(L, R);
		}
	}

	inline int query(int l, int r) {
		return query(1, 1, MAXN-1, l, r, -1);
	}

	inline void update(int k, int x) {
		query(1, 1, MAXN-1, k, k, x);
	}
} st;

inline void init() {
	cur_time = 0;
	cur_chain = 0;
	for (int i = 0; i < MAXN; i++) {
		edges[i].clear();
		weight[i] = 0;
		sz[i] = 0;
		level[i] = 0;
		memset(par[i], 0, sizeof par[i]);
		euler[i] = 0;
		pos[i] = 0;
		who[i] = 0;
		chain[i] = 0;
		same[i].clear();
	}
}

int dfs_init(int u, int p = -1) {
	sz[u] = 1;
	for (auto ed : edges[u]) if (ed.fi != p) {
		par[ed.fi][0] = u;
		level[ed.fi] = level[u] + 1;
		sz[u] += dfs_init(ed.fi, u);
	}
	return sz[u];
}

void dfs_euler(int u, int p = -1) {

	pii heavy{-1, -1};
	for (auto ed : edges[u]) if (ed.fi != p)
		heavy = heavy.fi != -1 ? sz[ed.fi] <= sz[heavy.fi] ? heavy : ed : ed;

	if (heavy.fi != -1) { // chama pro heavy
		// cout << "[H] " << u << " -> " << heavy.fi << "\n";
		pos[heavy.se] = ++cur_time;
		ini[u] = cur_time;
		euler[cur_time] = weight[heavy.se];
		chain[heavy.se] = cur_chain;
		same[cur_chain].eb(heavy.se);
		who[heavy.fi] = heavy.se;
		pai[heavy.se] = u;
		dfs_euler(heavy.fi, u);
	}
	for (auto ed : edges[u]) if (ed.fi != p && ed != heavy) {
		// cout << "[N] " << u << " -> " << ed.fi << "\n";
		pos[ed.se] = ++cur_time;
		euler[cur_time] = weight[ed.se];
		chain[ed.se] = ++cur_chain;
		same[cur_chain].eb(ed.se);
		who[ed.fi] = ed.se;
		pai[ed.se] = u;
		dfs_euler(ed.fi, u);
	}
}

inline int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
	for (int b = MAXL-1; ~b; b--)
		if (level[u] - (1 << b) >= level[v])
			u = par[u][b];

	if (u == v) return u;

	for (int b = MAXL-1; ~b; b--) {
		if (par[u][b] != par[v][b]) {
			u = par[u][b];
			v = par[v][b];
		}
	}

	return par[u][0];
}

inline int query(int u, int v) {
	// cout << "okay" << endl;
	if (u == v) return 0;

	int ans = 0;
	while(chain[who[u]] != chain[who[v]] && u != v) {
		int l = same[chain[who[u]]].front();
		// cout << "to vendo de " << pos[l] << " ate " << pos[who[u]] << endl;
		ans = max(ans, st.query(pos[l], pos[who[u]]));
		u = pai[l];
	}
	
	if (u == v) return ans;
	return max(ans, st.query(ini[v], pos[who[u]]));
}

inline void _solve_(int __ntest__) {
	init();
	int n; cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].eb(v, i);
		edges[v].eb(u, i);
		weight[i] = w;
	}

	dfs_init(1);
	for (int i = 1; i < MAXL; i++)
		for (int u = 1; u <= n; u++)
			par[u][i] = par[par[u][i-1]][i-1];
	dfs_euler(1);
	st.init();

	for (int i = 1; i <= cur_time; i++) {
		// cout << euler[i] << " \n"[i == cur_time];
	}

	string op;
	while(cin >> op, op[0] != 'D') {
		int a, b; cin >> a >> b;
		if (op[0] == 'C') {
			st.update(pos[a], b);
		} else {


			int l = lca(a, b);
			cout << max(query(a, l), query(b, l)) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}