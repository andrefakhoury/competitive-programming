#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXL = 21;

vector<int> edges[MAXN];
int par[MAXL][MAXN], level[MAXN];

void dfs(int u) {
	for (int v : edges[u]) {
		if (level[v] == -1) {
			par[0][v] = u;
			level[v] = level[u] + 1;
			dfs(v);
		}
	}
}

void pre(int n, int root) {
	memset(level, -1, sizeof level);
	level[root] = 0;

	dfs(root);

	for (int i = 1; i < MAXL; i++)
		for (int u = 1; u <= n; u++)
			par[i][u] = par[i-1][par[i-1][u]];
}

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

bool isChild(int children, int parent) {
	return lca(children, parent) == parent;
}

int main() {
	int n, q; scanf("%d%d", &n, &q);

	int p = -1;
	for (int i = 1; i <= n; i++) {
		int u; scanf("%d", &u); u++;
		if (u) edges[u].push_back(i);
		else p = i;
	}

	pre(n, p);

	while(q--) {
		int x, y; scanf("%d%d", &x, &y);
		x++, y++;

		bool ans = level[x] > level[y];
		printf("%s\n", ans ? "Yes" : "No");
		ans &= isChild(x, y);
	}
}