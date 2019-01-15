
// pair<vertex, weight>
vector<pair<int, int> > edges[MAXN];
int dist[MAXN];

void dijkstra(int s) {
	memset(dist, INF, sizeof dist);

	dist[s] = 0;
	priority_queue<pair<int, int> > pq; //pair<weight, vertex>
	pq.push(make_pair(0, s));

	while(pq.size()) {
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < (int)edges[u].size(); i++) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
}