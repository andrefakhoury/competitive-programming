#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

bool vis[MAXN];
int n;
vector<int> edges[MAXN];

int dfs(int u) {
	vis[u] = true;

	int h = 0;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!vis[v]) h = max(h, dfs(v));
	}

	return 1 + h;
}

int main() {
	int x; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x != -1) edges[x].push_back(i);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		ans = max(ans, dfs(i));
	}

	printf("%d\n", ans);
}