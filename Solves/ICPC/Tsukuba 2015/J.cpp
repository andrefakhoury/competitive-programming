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

const int MAXN = 5e4 + 5, INF = 0x3f3f3f3f;

vector<int> edg[MAXN];
vector<int> rev[MAXN];
vector<int> sd[MAXN];

int tim[MAXN];
int inv_tim[MAXN];
int par[MAXN];
int sdom[MAXN];
int idom[MAXN];
int un[MAXN];
int path[MAXN];

pii query(int u) {
	if (u == un[u]) return {u, u};
	int p;
	tie(p, un[u]) = query(un[u]);
	if (sdom[p] < sdom[path[u]]) path[u] = p;
	return {path[u], un[u]};
}

int tt;
void dfs(int u) {
	tim[u] = ++tt;
	inv_tim[tt] = u;
	for (int v : edg[u]) {
		if (!tim[v]) {
			dfs(v);
			par[tim[v]] = tim[u];
		}
	}
}

void build() {
	for (int u = 1; u <= tt; u++) sdom[u] = idom[u] = un[u] = path[u] = u;
	for (int u = tt; u >= 1; u--) {
		for (int v : rev[inv_tim[u]]) {
			v = tim[v];
			if (v == 0) continue;
			if (v < u) sdom[u] = min(sdom[u], sdom[v]);
			else sdom[u] = min(sdom[u], sdom[query(v).fi]);
		}
		sd[sdom[u]].pb(u);

		for (int v : sd[u]) {
			int best = query(v).fi;
			if (sdom[best] >= u) idom[v] = u;
			else idom[v] = best;
		}

		for (int v : edg[inv_tim[u]]) {
			v = tim[v];
			if (v == 0) continue;
			if (par[v] == u) un[v] = u;
		}
	}

	for (int u = 1; u <= tt; u++) {
		if (idom[u] != sdom[u]) idom[u] = idom[idom[u]];
	}
}

int level_lca[MAXN];
int par_lca[MAXN][21];
vector<int> edtree[MAXN];
int ans_lca[MAXN];
int cost[MAXN];

void dfs_lca(int u, int p = 1) {
	for (int v : edtree[u]) if (v != p) {
		level_lca[v] = level_lca[u] + 1;
		par_lca[v][0] = u;
		ans_lca[v] = min(ans_lca[u], cost[v]);
		dfs_lca(v, u);
	}
}

inline int lca(int u, int v) {
	if (u == -1) return v;
	if (v == -1) return u;

	if (level_lca[u] < level_lca[v]) swap(u, v);

	for (int b = 20; ~b; b--) {
		if (level_lca[u] - (1 << b) >= level_lca[v]) {
			u = par_lca[u][b];
		}
	}

	if (u == v) return u;

	for (int b = 20; ~b; b--) {
		if (par_lca[u][b] != par_lca[v][b]) {
			u = par_lca[u][b];
			v = par_lca[v][b];
		}
	}

	return par_lca[u][0];
}

int main() {
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edg[u].eb(v);
		rev[v].pb(u);
	}

	dfs(1);
	build();

	for (int i = 1; i <= n; i++) {
		scanf("%d", cost+i);
	}

	for (int i = 1; i <= n; i++) {
		edtree[inv_tim[idom[tim[i]]]].eb(i);
	}

	ans_lca[1] = cost[1];
	dfs_lca(1);
	for (int b = 1; b <= 20; b++) {
		for (int u = 1; u <= n; u++) {
			par_lca[u][b] = par_lca[par_lca[u][b-1]][b-1];
		}
	}

	int q; scanf("%d", &q);
	while(q--) {
		int k; scanf("%d", &k);
		int l = -1;
		while(k--) {
			int u; scanf("%d", &u);
			l = lca(u, l);
		}

		printf("%d\n", ans_lca[l]);
	}
}