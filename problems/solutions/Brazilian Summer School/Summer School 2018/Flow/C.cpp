#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e10;
const double EPS = 1e-7;
const int MAXN = 1e3 + 5;

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

	void add_edge(int v, int u, long long cap, long long flw = 0) {
		edges.emplace_back(v, u, cap);
		if (flw) edges.back().flow = flw;
		
		edges.emplace_back(u, v, 0);
		if (flw) edges.back().flow = -flw;

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

	long long flow(long long f) {
		bool ok = true;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);

			if (!bfs()) {
				break;
			}

			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf)) {
				f += pushed;
			}

			ok = false;
		}

		if (ok) return -1;
		return f;
	}
};

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<int> > edges(n+1);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		if (!k) continue;

		edges[i].resize(k);
		for (int& j : edges[i])
			scanf("%d", &j);
	}

	vector<int> matchn(n+1);
	vector<int> matchm(m+1);

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		sum += x != 0;
		matchn[i] = x;
		matchm[x] = i;
	}

	int SRC = 0, SNK = n+m+1;
	Dinic f(n+m+2, SRC, SNK);

	for (int i = 1; i <= m; i++)
		f.add_edge(i+n, SNK, 1, matchm[i] ? 1 : 0);

	for (int i = 1; i <= n; i++) {
		f.add_edge(SRC, i, 1, matchn[i] ? 1 : 0);
		for (int j : edges[i])
			f.add_edge(i, j+n, 1, j == matchn[i]);
	}

	long long ans = f.flow(sum);
	if (ans == -1) printf("YES\n");
	else {
		printf("NO\n%lld\n", ans);
		for (FlowEdge ed : f.edges) {
			if (ed.u != SRC && ed.v != SNK && ed.v != SRC && ed.u != SNK && ed.flow == 1) {
				printf("%d %d\n", ed.v, ed.u-n);
			}
		}
	}
	
}