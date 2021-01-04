#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
const int MAXL = 21;

int level[MAXN];
int par[MAXN][MAXL];
vector<int> edges[MAXN];
int color[MAXN];
int cur_t;

void dfs_init(int u, int p=-1) {
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		par[v][0] = u;
		dfs_init(v, u);
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
	return par[v][0];
}

inline int dist(int u, int v) {
	return level[u] + level[v] - 2 * level[lca(u, v)];
}

inline void _solve_(int __ntest__) {
	int n, m; rd(n, m);

	for (int i = 2; i <= n; i++) {
		int x; rd(x);
		edges[i].eb(x);
		edges[x].eb(i);
	}
	
	dfs_init(1);
	for (int b = 1; b < MAXL; b++) {
		for (int u = 1; u <= n; u++) {
			par[u][b] = par[par[u][b-1]][b-1];
		}
	}

	set<int> white;
	for (int i = 1; i <= n; i++) white.emplace(i);

	while(m--) {
		int u; rd(u);
		bool has = false;
		if (color[u] == 1) {
			has = true;
			color[u] = 0;
			white.emplace(u);
		}

		pii ans = {0, u};
		for (int w : white) ans = max(ans, {dist(u, w), w});
		printf("%d\n", ans.se);

		if (!has) {
			color[u] = 1;
			white.erase(u);
		}
	}

	for (int i = 1; i <= n; i++) {
		edges[i].clear();
		color[i] = 0;
	}
	cur_t = 0;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}