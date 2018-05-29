#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 100005;

vector<pair<int, int> > edges[N];
int dist[N];

void dijkstra(int s) {
	
    priority_queue<pair<int, int> > pq;
	memset(dist, -1, sizeof(dist));
	pq.push({s, 0});
	dist[s] = 0;
	
	while(pq.size()) {
		int u = pq.top().first;
		pq.pop();
		
		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;
			
			if (dist[v] == -1) {
				dist[v] = dist[u] + w;
				pq.push({v, dist[v]});
			} else if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({v, dist[v]});
			}
		}
		
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int N, M, A, x, y, z;
	cin >> N >> M >> A;
	
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> z;
		
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}
	
	dijkstra(A);
	
	for (int i = 1; i <= N; i++) {
		
		cout << dist[i] << endl;
	}
	
	
	return 0;
}