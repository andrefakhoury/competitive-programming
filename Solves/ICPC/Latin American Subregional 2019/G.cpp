#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const double INF = 1e12;
const double EPS = 1e-8;

struct MCMF {
	struct Edge {
		int to, cost, cap, flow, rid;

		Edge () {}

		Edge (int a, int b, int c, int d, int e) : 
			to(a), cost(b), cap(c), flow(d), rid(e) {}
	};

	vector<vector<Edge> > edges;
	vector<int> h, dist;
	vector<pii> par;

	int n, s, t;

	MCMF(int n, int s, int t) : n(n), s(s), t(t) {
		edges.resize(n+1);
		h.resize(n+1);
		dist.resize(n+1);
		par.resize(n+1);
	}

	void add_edge(int u, int v, int cost, int cap) {
		edges[u].emplace_back(v, cost, cap, 0, edges[v].size());
		edges[v].emplace_back(u, -cost,  0, 0, edges[u].size() - 1);
	}

	void bellman_ford(int s) {
		fill(h.begin(), h.end(), INF);
		h[s] = 0;

		for (int i = 0; i < n - 1; i++) {
			for (int at = 0; at < n; at++) {
				for (int j = 0; j < (int)edges[at].size(); j++) {
					if (!edges[at][j].cap)  continue;
					int next = edges[at][j].to, w = edges[at][j].cost;
					h[next] = min(h[next], h[at] + w);
				}
			}
		}
	}

	bool dijkstra(int s, int t) {
		fill(dist.begin(), dist.end(), INF);
		fill(par.begin(), par.end(), mk(-1, -1));
		priority_queue<pii, vector<pii>, greater<pii> > pq;

		dist[s] = 0;
		pq.emplace(0, s);
		bool ret = false;

		while (pq.size()) {
			int at = pq.top().se;
			int d = pq.top().fi;
			pq.pop();

			if (at == t) ret = true;
			if (d != dist[at]) continue;

			for (int i = 0; i < (int)edges[at].size(); i++) {
				Edge edg = edges[at][i];
				int next = edg.to;
				if (edg.cap - edg.flow <= 0) continue;
				ll w = dist[at] + edg.cost + h[at] - h[next];
				if (dist[next] > w) {
					dist[next] = w;
					par[next] = {at, i};
					pq.emplace(dist[next], next);
				}
			}
		}

		for (int i = 0; i <= n; i++)
			if (h[i] < INF and dist[i] < INF)
				h[i] += dist[i];

		return ret;
	}

	pii max_flow() {
		int cost = 0, flow = 0;
		bellman_ford(s);

		while (dijkstra(s, t)) {
			int f = INF;
			for (int at = t; at != s; at = par[at].fi) {
				Edge edg = edges[par[at].fi][par[at].se];
				f = min(f, edg.cap - edg.flow);
			}
			flow += f;
			for (int at = t; at != s; at = par[at].fi) {
				Edge &edg = edges[par[at].fi][par[at].se];
				edg.flow += f;
				edges[edg.to][edg.rid].flow -= f;
				cost += edg.cost * f;
			}
		}

		return mk(cost, flow);
	}
};

int n;
inline int get(int i, int j) {
	return (i-1) * n + j;
}

double m[101][101];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; scanf("%d", &x);
			m[i][j] = log(x);
		}
	}

	int SRC = 0, SNK = n * n + 1;
	Dinic f(n * n + 2, SRC, SNK);

	for (int i = 1; i <= n; i++) {
		f.add_edge(SRC, get(i, 1), m[i][1]);
		f.add_edge(get(i, n), SNK, m[i][n]);
		for (int j = 1; j < n; j++) for (int k = 1; k <= n; k++)
			f.add_edge(get(i, j), get(k, j+1), m[k][j+1]);
	}

	f.flow();
	vector<int> ans;
	for (FlowEdge ed : f.edges) {
		if (ed.flow > 0) ans.eb(ed.u);
	}

	for (int x : ans) {
		int y = (x+n-1)/n;
		printf("%d ", y);
	}

	printf("\n");
}