#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f;
const int MAXN = 200;

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

int n, m, in[MAXN], nxt[MAXN];
vector<int> edges[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
	}

	int SRC = 0, SNK = n+n+1;
	Dinic f(n+n+2, SRC, SNK);
	for (int i = 1; i <= n; i++) {
		f.add_edge(SRC, i, 1);
		f.add_edge(i+n, SNK, 1);
		for (int j : edges[i])
			f.add_edge(i, j+n, INF);
	}

	f.flow();
	for (FlowEdge ed : f.edges) {
		if (ed.v >= 1 && ed.v <= n && ed.u > n && ed.u <= n+n && ed.flow == 1) {
			nxt[ed.v] = ed.u - n;
			in[ed.u-n]++;
		}
	}

	vector<int> ans;
	for (int u = 1; u <= n; u++) if (in[u] == 0) ans.eb(u);

	printf("%ld\n", ans.size());
	for (int u : ans) {
		printf("%d ", u);
		while(nxt[u]) {
			u = nxt[u];
			printf("%d ", u);
		}
		printf("\n");
	}
}