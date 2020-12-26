#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

long long dijkstra(int n, int s, int t, vector<vector<pii> >& edges) {
	vector<long long> dist(n);
	fill(dist.begin(), dist.end(), -1);
	priority_queue<pii> pq;

	dist[s] = 0;
	pq.push({0, s});

	while(pq.size()) {
		int u = pq.top().second;
		pq.pop();

		for (pii p : edges[u]) {
			int v = p.first;
			int w = p.second;

			if (dist[v] == -1 || dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({-dist[v], v});
			}
		}
	}

	return dist[t];
}

int main() {
	int t, caso = 0; scanf("%d", &t);
	while(t--) {
		int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
		vector<vector<pii> > edges(n);

		for (int i = 1; i <= m; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			edges[u].push_back({v, w});
			edges[v].push_back({u, w});
		}

		printf("Case #%d: ", ++caso);
		long long ans = dijkstra(n, a, b, edges);

		if (ans >= 0) printf("%lld\n", ans);
		else printf("unreachable\n");
	}
}