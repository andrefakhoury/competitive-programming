#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXL = 21;

vector<int> edges[MAXN];

int par[MAXL][MAXN]; // par[2^i][u]
int level[MAXN];

void dfs(int u) {
	for (int v : edges[u]) {
		if (level[v] == -1) {
			par[0][v] = u;
			level[v] = level[u] + 1;
			dfs(v);
		}
	}
}

/** Returns the LCA of u and v */
int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);

	for (int i = MAXL-1; i > -1; i--)
		if (level[u] - (1 << i) >= level[v]) u = par[i][u];

	if (u == v) return u;

	for (int i = MAXL-1; i > -1; i--)
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}

	return par[0][u];
}

int walk(int u, int p) {	
	for (int i = MAXL-1; i > -1; i--) {
		if (p & (1 << i)) {
			if (level[u] == 0) return 0;
			u = par[i][u];
		}
	}

	return u;
}

/** Preprocess the levels and stuff */
void pre(int n, int root) {
	memset(level, -1, sizeof level);
	level[root] = 0;

	dfs(root);

	for (int i = 1; i < MAXL; i++)
		for (int u = 1; u <= n; u++)
			par[i][u] = par[i-1][par[i-1][u]];
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