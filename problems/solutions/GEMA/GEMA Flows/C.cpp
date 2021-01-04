#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string T; cin >> T;

	int n; cin >> n;
	vector<string> v(n);
	vector<int> a(n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i] >> a[i];
		sum += v[i].size();
	}

	int s = 26, t = 27, auxT = 28;
	int N = 1 + 26 + sum + n + 1;
	MCMF f(N, s, t);

	vector<int> freq(26, 0);
	for (char c : T) freq[c-'a']++;
	for (int i = 0; i < 26; i++)
		f.add_edge(s, i, 0, freq[i]);

	int cur = 28;
	for (int i = 0; i < n; i++) {
		int curString = ++cur;
		for (char c : v[i]) {
			int curChar = ++cur;
			f.add_edge(c-'a', curChar, i+1, 1);
			f.add_edge(curChar, curString, 0, 1);
		}
		f.add_edge(curString, auxT, 0, a[i]);
	}
	f.add_edge(auxT, t, 0, T.size());

	pii ans = f.max_flow();
	if (ans.se != int(T.size())) cout << -1 << '\n';
	else cout << ans.fi << '\n';

	return 0;
}