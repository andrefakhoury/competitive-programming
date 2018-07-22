#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back

vector<int> edges[MAXN];
int vis[MAXN];

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < edges[u].size(); i++) {
		if (!vis[edges[u][i]]) dfs(edges[u][i]);
	}
}

int main() {
	int n, m, x, y; scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d", &x, &y);
		edges[x].pb(y);
		edges[y].pb(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}		
	}

	printf("%d\n", ans);
	return 0;
}