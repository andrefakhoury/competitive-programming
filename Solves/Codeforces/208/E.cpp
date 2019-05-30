#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXL = 21;

vector<int> edges[MAXN];
int par[MAXL][MAXN]; // par[2^i][u]
int level[MAXN];
vector<int> perLevel[MAXN];

void dfs(int u) {
	for (int v : edges[u]) {
		par[0][v] = u;
		level[v] = level[u] + 1;
		perLevel[level[v]].push_back(v);
		dfs(v);
	}
}

int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);

	for (int i = MAXL-1; i > -1; i--)
		if (level[u] - (1 << i) >= level[v]) u = par[i][u];

	if (u == v) return u;

	for (int i = MAXL-1; i > -1; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
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

int solve(int v, int p, int n, vector<int>& roots) {
	int l = walk(v, p);
	if (l == 0) return 0;
	
	int ans = 0;
	for (int u : perLevel[level[v]]) {
		if (u == v) continue;
		int cur = walk(u, p);
		ans += cur && cur == l;
	}

	return ans;
}

int main() {
	int n; scanf("%d", &n);

	vector<int> roots;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (x == 0) roots.push_back(i);
		else edges[x].push_back(i);
	}

	memset(level, -1, sizeof level);
	for (int r : roots) level[r] = 0;
	for (int r : roots) dfs(r);

	for (int i = 1; i < MAXL; i++)
		for (int u = 1; u <= n; u++)
			par[i][u] = par[i-1][par[i-1][u]];

	int q; scanf("%d", &q);
	while(q--) {
		int v, p; scanf("%d%d", &v, &p);
		printf("%d ", solve(v, p, n, roots));
	} printf("\n");

	return 0;
}