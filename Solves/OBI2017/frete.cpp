#include <bits/stdc++.h>

using namespace std;

#define MAXN 101
#define MAXM 1001

typedef pair<int, int> pii;

vector<pii> edges[MAXN];
int dist[MAXN];

void dijkstra(int s) {
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	priority_queue<int> pq;
	pq.push(s);
	while(pq.size()) {
		int u = pq.top();
		pq.pop();
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;

			if (dist[v] == -1) {
				dist[v] = dist[u] + w;
				pq.push(v);
			} else if (dist[v] > dist[u] + w) {
				dist[v] = dist[u]+w;
				pq.push(v);
			}
		}
	}
}

int main() {
	int N, M;
	int a, b, c;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		edges[a].push_back({b, c});
		edges[b].push_back({a, c});
	}
	dijkstra(1);
	printf("%d\n", dist[N]);
	return 0;
}