vector<int> edges[MAXN];
int dist[MAXN];

void bfs(int s) {
	memset(dist, -1, sizeof dist);

	dist[s] = 0;
	queue<int> q;
	q.push(s);

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < (int)edges[u].size(); i++) {
			int v = edges[u][i];

			if (dist[v] == -1) {
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}