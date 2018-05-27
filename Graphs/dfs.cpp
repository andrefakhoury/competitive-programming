vector<int> edges[MAXN];
int vis[MAXN]; // visited positions

void dfs(int u) {
	vis[u] = 1;
	for(int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if(vis[v] == 0) dfs(v);
	}
}
