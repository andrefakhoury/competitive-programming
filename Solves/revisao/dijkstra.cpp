#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;

vector<pii> edges[MAXN];
int dist[MAXN], pred[MAXN];

void dijkstra(int s) {
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	pred[s] = -1;
	priority_queue<int> pq;
	pq.push(s);
	while(pq.size()) {
		int u = pq.top();
		pq.pop();
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;
			if (dist[v] == -1 || dist[v] > dist[u]+w) {
				dist[v] = dist[u]+w;
				pred[v] = u;
				pq.push(v);
			}
		}
	}
}

int main() {
	int n; //vertives
	int m; //arestas
	int A; //inicial
	scanf("%d%d%d", &n, &m, &A);

	int x, y, w;
	while (m--) {
		scanf("%d%d%d", &x, &y, &w);
		edges[x].pb(mp(y, w));
		edges[y].pb(mp(x, w));
	}

	dijkstra(A);
	for (int i = 1; i <= n; i++)
		printf("%d\n", dist[i]);
	return 0;


}