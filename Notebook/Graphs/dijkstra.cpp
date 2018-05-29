int dist[MAXN];
int processed[MAXN];
vector<pii> edges[MAXN]; //{next, weight}

void dijkstra(int s) { //O(MlogN)
	for (int i = 1; i <= MAXN-1; i++) dist[i] = inf;
	dist[s] = 0;
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({dist[s], s});
	
	while (1) {
		int u = -1;
		
		while (!pq.empty()) {
			int atual = pq.top().second;
			pq.pop();
			
			if (!processed[atual]) {
				u = atual;
				break;
			}
		}
		
		if(u == -1) break;
		
		processed[u] = true;
		
		for(int i = 0; i < (int)edges[u].size(); i++) {
			int v  = edges[u][i].first;
			int w = edges[u][i].second; //weight
			
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}