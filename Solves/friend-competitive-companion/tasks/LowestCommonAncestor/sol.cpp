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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
const int L = 21;

vector<int> edges[MAXN];
int par[MAXN][L];
int level[MAXN];

int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
	for (int b = L-1; ~b; b--) {
		if (level[u] - (1 << b) >= level[v]) u = par[u][b];
	}
	if (u == v) return u;
	for (int b = L-1; ~b; b--) {
		if (par[u][b] != par[v][b]) {
			u = par[u][b];
			v = par[v][b];
		}
	}
	return par[u][0];
}

void dfs(int u, int p) {
	par[u][0] = p;
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}

inline void init(int n, int root) {
	level[root] = 0;
	dfs(root, root);
	for (int b = 1; b < L; b++) {
		for (int i = 1; i <= n; i++) {
			par[i][b] = par[par[i][b - 1]][b - 1];
		}
	}
}

int main() {
	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	init(n, 1);

	int q; rd(q);
	for (int i = 0; i < q; i++) {
		int r, u, v; rd(r, u, v);
		int ans = lca(r, u) ^ lca(r, v) ^ lca(u, v);
		printf("%d\n", ans);
	}
}
