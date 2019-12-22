#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e4 + 5;

struct FlowEdge {
	int v, u;
	long long cap, flow = 0;
	FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
	const long long flow_inf = 1e18;
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

int n, m, mat[55][55];
int get(int i, int j) {
	return i*m + j;
}

void mark(int x, int k) {
	while(x--) {
		int i, j; scanf("%d%d", &i, &j);
		mat[i-1][j-1] = k;
	}
}

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

int op[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	scanf("%d%d", &n, &m);
	int k1, k2; scanf("%d%d", &k1, &k2);

	mark(k1, 1); // mountain
	mark(k2, 2); // wall

	pii A, B;
	scanf("%d%d%d%d", &A.fi, &A.se, &B.fi, &B.se);

	int N = n*m, SRC = get(A.fi-1, A.se-1), SNK = get(B.fi-1, B.se-1) + N;
	Dinic f(2*N, SRC, SNK);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) continue;
			int u = get(i, j);

			f.add_edge(u, N+u, mat[i][j] == 2 ? 1 : INF);
			for (int k = 0; k < 4; k++) {
				int I = i+op[k][0], J = j+op[k][1];
				if (!valid(I, J) || mat[I][J] == 1) continue;

				int v = get(I, J);
				f.add_edge(N+u, v, INF);
			}
		}
	}

	ll ans = f.flow();
	if (ans > k2) return !printf("-1\n");

	printf("%lld\n", ans);

	for (FlowEdge ed : f.edges) {
		if (ed.cap == 1 && ed.flow == 1 && f.level[ed.v] != -1 && f.level[ed.u] == -1) {
			printf("%d %d\n", ed.v/m + 1, ed.v%m + 1);
		}
	}

	return 0;
}