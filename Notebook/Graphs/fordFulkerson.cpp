#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int cap[MAXN][MAXN]; //capacity matrix
int res[MAXN][MAXN]; //residual capacity

int parent[MAXN];	//i got introduced by parent[i]
bool vis[MAXN];

bool bfs(int s, int t, int V) {
	memset(vis, 0, sizeof vis);

	queue<int> q;
	q.push(s);
	vis[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (!vis[v] && res[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				vis[v] = true;
			}

			if (vis[t]) return true;
		}
	}

	return vis[t]; //if the sink is not visited, the path-finding is done
}

//Ford-Fulkerson - Edmond Karp Implementation
int fordFulkerson(int s, int t, int V) { //O(V*V + V*E*E)
	if (s == t) return -1;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			res[i][j] = cap[i][j];

	memset(parent, 0, sizeof parent);
	int maxFlow = 0;

	while(bfs(s, t, V)) {
		int flow = INF;
		for (int v = t; v != s; v = parent[v]) {
			printf("%d-%d\n", parent[v], v);

			int u = parent[v];
			flow = min(flow, res[u][v]);
		}

		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			res[u][v] -= flow;
			res[v][u] += flow;
		}

		maxFlow += flow;
	}

	return maxFlow;
}


int main() {

	int t; scanf("%d", &t);
	while(t--) {
		memset(cap, 0, sizeof cap);

		int n, m, s, t, x, y, w; scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &w);
			cap[x][y] += w;
		}

		s = 1;
		t = n;

		printf("%d\n", fordFulkerson(s, t, n));
	}

	return 0;
}