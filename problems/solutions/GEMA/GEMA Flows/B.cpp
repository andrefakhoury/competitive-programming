#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const long long flow_inf = 1e18;

struct FlowEdge {
	int v, u;
	long long cap, flow;
	FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {
		flow = 0;
	}
};

struct Dinic {
	vector<FlowEdge> edges;
	vector<vector<int> > adj;
	int n, m;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		m = 0;
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	inline void add_edge(int v, int u, long long cap) {
		edges.pb(FlowEdge(v, u, cap));
		edges.pb(FlowEdge(u, v, 0));
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (size_t i = 0u; i < adj[v].size(); i++) {
				int id = adj[v][i];
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

int n, m, k;
inline int get(int x, int y) {
	return x * m + y;
}

inline bool can(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int op[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	scanf("%d%d%d", &n, &m, &k);

	set<int> st;
	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d%d", &x, &y);
		st.insert(get(y-1, x-1));
	}

	int N = n * m, qtt = N - k;
	if (qtt%2) return !printf("NO\n");
	if (!qtt) return !printf("YES\n");

	int cap = qtt/2, auxS = N, auxT = N+1, s = N+2, t = N+3;
	
	Dinic f(N+4, s, t);
	f.add_edge(s, auxS, cap);
	f.add_edge(auxT, t, cap);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = get(i, j);
			if (st.count(u)) continue;

			// sai dele
			if ((i + j) % 2) {
				f.add_edge(u, auxT, 1);
				continue;
			}
			
			// entra nele
			f.add_edge(auxS, u, 1);
			for (int ii = 0; ii < 4; ii++) {
				int I = i + op[ii][0], J = j + op[ii][1], v = get(I, J);
				if (!can(I, J) || st.count(v)) continue;

				f.add_edge(u, v, 1);
			}
		}
	}

	int ans = f.flow();
	printf("%s\n", ans == cap ? "YES" : "NO");

	return 0;
}