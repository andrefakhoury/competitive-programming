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
const int MAXN = 1e5 + 5;

struct EdmondsKarp {
	vector<vector<ll> > capacity;
	vector<vector<int> > edges;
	int n, s, t;

	EdmondsKarp(int n, int s, int t) : n(n), s(s), t(t) {
		edges = vector<vector<int> >(n+1);
		capacity = vector<vector<ll> >(n+1, vector<ll>(n+1));
	}

	void add_edge(int u, int v, int c) {
		edges[u].pb(v);
		edges[v].pb(u);
		capacity[u][v] += c;
	}

	ll bfs(int s, int t, vector<int>& par) {
		fill(par.begin(), par.end(), -1);
		par[s] = -2;
		queue<pair<int, ll> > q;
		q.push(mk(s, INF));

		while (!q.empty()) {
			int u = q.front().first;
			ll flow = q.front().second;
			q.pop();

			for (size_t i = 0u; i < edges[u].size(); i++) {
				int v = edges[u][i];
				if (par[v] == -1 && capacity[u][v]) {
					par[v] = u;
					ll new_flow = min(flow, capacity[u][v]);
					if (v == t) return new_flow;
					q.push(mk(v, new_flow));
				}
			}
		}

		return 0;
	}

	ll flow() {
		ll ans = 0;
		vector<int> par(n+1);
		ll new_flow;

		while (new_flow = bfs(s, t, par), new_flow) {
			ans += new_flow;
			int cur = t;
			while (cur != s) {
				int prev = par[cur];
				capacity[prev][cur] -= new_flow;
				capacity[cur][prev] += new_flow;
				cur = prev;
			}
		}

		return ans;
	}
};

int main() {
	int n, m;
	while(~scanf("%d%d", &m, &n)) {
		EdmondsKarp f(n, 1, n);

		for (int i = 0; i < m; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			f.add_edge(u, v, w);
		}

		printf("%lld\n", f.flow());
	}

	return 0;
}