#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 200;

struct Dinic {
	const long long flow_inf = 1e18;
	
	struct FlowEdge {
		int v, u;
		long long cap, flow = 0;
		FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
	};

	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int v, int u, long long cap) {
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	long long dfs(int v, long long pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	long long flow() {
		long long f = 0;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

char mat[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
int n;

int get(int i, int j) {
	return (i-1)*n + j;
}

int main() {
	while(~scanf("%d", &n)) {
		memset(mat, 0, sizeof mat);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %c", &mat[i][j]);
			}
		}

		int R = 0, C = n*n;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (mat[i][j] == '.') {
			R += mat[i][j] != mat[i][j-1];
			row[i][j] = R;
		}

		for (int j = 1; j <= n; j++) for (int i = 1; i <= n; i++) if (mat[i][j] == '.') {
			C += mat[i][j] != mat[i-1][j];
			col[i][j] = C;
		}

		int SRC = 0, SNK = C+1;
		Dinic f(C+2, SRC, SNK);

		for (int i = 1; i <= R; i++) f.add_edge(SRC, i, 1);
		for (int i = n*n+1; i <= C; i++) f.add_edge(i, SNK, 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (mat[i][j] == '.')
				f.add_edge(row[i][j], col[i][j], 1);

		printf("%lld\n", f.flow());
	}
}