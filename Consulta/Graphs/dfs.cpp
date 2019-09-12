
vector<int> edges[MAXN];
bool vis[MAXN];

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		int v = edges[u][i];
		if (!vis[v]) dfs(v);
	}
}
