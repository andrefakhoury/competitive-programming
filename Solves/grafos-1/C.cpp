#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define pb push_back
#define mp make_pair
#define mset(x, y) memset(x, y, sizeof x)

vector<int> edges[MAXN];
int vis[MAXN], v;

void dfs(int u, int ign1, int ign2) {
	vis[u] = 1;
	for (int i = 0; i < edges[u].size(); i++) {
		v = edges[u][i];
		if ((u == ign1 && v == ign2) || (u == ign2 && v == ign1))
			continue;
		if (!vis[v]) dfs(v, ign1, ign2);
	}
}

int main() {
	int n, m, a, b, x, y; //a -> b
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		edges[x].pb(y);
		edges[y].pb(x);
	}

	dfs(a, 0, 0);
	if (!vis[b]) return !printf("NAO\n");

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)edges[i].size(); j++) {
			mset(vis, 0);
			dfs(a, i, edges[i][j]);
			if (!vis[b]) return !printf("NAO\n");
		}
	}

	printf("SIM\n");
	return 0;
}