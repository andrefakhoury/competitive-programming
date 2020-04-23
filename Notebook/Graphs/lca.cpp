#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXL = 21;

vector<int> edges[MAXN];

int ans[MAXN][MAXL];
int par[MAXN][MAXL]; // par[u][2^i]
int level[MAXN];

void dfs_init(int u, int p=-1) {
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		par[v][0] = u;
		ans[v][0] = 1;
		dfs_init(v, u);
	}
}

/** Returns the LCA of u and v */
int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
 
	int cur = 0x3f3f3f3f;
	for (int i = MAXL-1; i >= 0; i--) {
		if (level[u] - (1 << i) >= level[v]) {
			cur = min(cur, ans[u][i]);
			u = par[u][i];
		}
	}
 
	// if (u == v) return cur;
	if (u == v) return u;
 
	for (int i = MAXL-1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			cur = min(cur, ans[u][i]);
			cur = min(cur, ans[v][i]);
 
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
	// return min(min(cur, ans[u][0]), ans[v][0]);
}

/** Preprocess the levels and stuff */
void pre(int n, int root) {
	memset(ans, 0x3f, sizeof ans);
	level[root] = 0;

	dfs_init(root);
	for (int i = 1; i < MAXL; i++) {
		for (int u = 1; u <= n; u++) {
			par[u][i] = par[par[u][i-1]][i-1];
			ans[u][i] = min(ans[u][i-1], par[u][i]);
		}
	}
}

int main() {
	int n, root; scanf("%d%d", &n, &root);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
	}

	pre(n, root);

	int q; scanf("%d", &q);
	while(q--) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%d\n", lca(u, v));
	}

	return 0;
}