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
const int MAXN = 1e5 + 5;

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

int main() {
	int n, q;
	while(~scanf("%d%d", &n, &q)) {
		vector<vector<int> > groups(n);
		for (auto& v : groups) {
			int k; scanf("%d", &k);
			v.resize(k);
			for (int& i : v) scanf("%d", &i);
		}

		while(q--) {
			int k; scanf("%d", &k);
			set<int> need;
			set<int> st;

			for (int i = 0; i < k; i++) {
				int x; scanf("%d", &x);
				need.emplace(x);
			}

			int SRC = n+n+1, SNK = n+n+2;
			Dinic f(n+n+3, SRC, SNK);

			for (int i = 0; i < n; i++) {
				f.add_edge(SRC, i, 1);

				if ((int)groups[i].size() < n) f.add_edge(i, 0+n, 1);
				for (int x : groups[i]) {
					if (need.count(x)) st.emplace(i);
					f.add_edge(i, x+n, 1);
				}
				if ((int)groups[i].size() != n) st.emplace(i);
			}

			for (int x : need) f.add_edge(x+n, SNK, 1);

			if ((int)st.size() == n && f.flow() >= k) printf("Y\n");
			else printf("N\n");
		}
	}
}