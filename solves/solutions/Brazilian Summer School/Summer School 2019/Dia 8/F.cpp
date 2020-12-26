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

pii v[MAXN];
int qtt[MAXN];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		memset(v, 0, sizeof v);
		memset(qtt, 0, sizeof qtt);

		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &v[i].fi, &v[i].se);
			qtt[v[i].fi]++;
			qtt[v[i].se]++;
		}

		int SRC = 0, SNK = 2 * n + 1, ans = 0;
		for (int w = 1; w <= n; w++) {
			Dinic f(2 * n + 2, SRC, SNK);

			for (int i = 1; i <= n; i++) {
				if (i == w) continue;
				if (v[i].fi == w || v[i].se == w) continue;

				f.add_edge(i, v[i].fi + n, 1);
				f.add_edge(i, v[i].se + n, 1);
			}

			for (int i = 1; i <= n; i++) {
				if (i == w) continue;

				f.add_edge(SRC, i, 1);
				f.add_edge(i+n, SNK, qtt[w] - 1 - ((v[w].fi == i || v[w].se == i) ? 1 : 0));
			}

			ll flow = f.flow();

			bool won = flow != n - qtt[w] - 1;
			ans += won;
		}

		printf("%d\n", ans);
	}

}