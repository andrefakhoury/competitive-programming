#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005, INF = 0x3f3f3f3f;

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


int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
	}

	dijkstra(1);

	printf("%d\n", dist[n]);

}