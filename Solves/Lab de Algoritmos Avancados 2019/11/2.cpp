#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = 0x3f3f3f3f;

int bfs(int s, int t, int n, vector<int>& parent, vector<vector<int>>& adj, vector<vector<int> > capacity) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int> > q;
	q.push({s, INF});

	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, capacity[cur][next]);
				if (next == t) return new_flow;
				q.push({next, new_flow});
			}
		}
	}

	return 0;
}

void mincut(int s, int t, int n, vector<vector<int> >& adj, vector<vector<int> > capacity) {
	int flow = 0;
	vector<int> parent(n+1);
	int new_flow;

	while (new_flow = bfs(s, t, n, parent, adj, capacity), new_flow) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	stack<int> st;
	st.push(s);
	vector<bool> vis(n+1, 0);

	while(st.size()) {
		int u = st.top();
		st.pop();

		vis[u] = true;

		for (int v : adj[u]) {
			if (capacity[u][v] > 0) {
				if (!vis[v]) st.push(v);
			}
		}
	}

	for (int u = 1; u <= n; u++) {
		if (!vis[u]) continue;

		for (int v : adj[u]) {
			if (!vis[v]) {
				printf("%d %d\n", u, v);
			}
		}
	}

	printf("\n");
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m), n || m) {
		vector<vector<int> > edges(n+1);
		vector<vector<int> > capacity(n+1);
		for (int i = 1; i <= n; i++) capacity[i].resize(n+1);

		for (int i = 1; i <= m; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);

			edges[u].push_back(v);
			edges[v].push_back(u);

			capacity[u][v] += w;
			capacity[v][u] += w;
		}

		mincut(1, 2, n, edges, capacity);
	}

	return 0;
}