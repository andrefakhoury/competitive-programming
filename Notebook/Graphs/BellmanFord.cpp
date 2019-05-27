#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

int n, dist[MAXN], par[MAXN];
vector<pii> edges[MAXN];
vector<int> tpsrt;
bool vis[MAXN];

void dfs(int u) {
	vis[u] = true;

	for (pii p : edges[u])
		if (!vis[p.fi]) dfs(p.fi);

	tpsrt.push_back(u);
}

// Can be used on DAGs
void bellmanford_toposort(int s) {
	memset(vis, 0, sizeof vis);
	tpsrt.clear();

	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	reverse(tpsrt.begin(), tpsrt.end());

	cout << "Toposort: ";
	for (int u : tpsrt) {
		cout << u << ' ';
	} cout << endl;

	memset(dist, 0x3f, sizeof dist);
	memset(par, -1, sizeof par);
	dist[s] = 0;

	for (int u : tpsrt) {
		for (pii p : edges[u]) {
			int v = p.fi, w = p.se;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				par[v] = u;
			}
		}
	}
}

void bellmanford(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(par, -1, sizeof par);

	for (int cnt = 1; cnt <= n-1; cnt++) {
		bool converged = true;
		for (int u = 1; u <= n; u++) {
			for (int v : edges[u]) {
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					par[v] = u;
					converged = false;
				}
			}
		}
		if (converged) break;
	}

	// testa ciclos negativos
	// TODO
}

int main() {
	int m; cin >> n >> m;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].emplace_back(v, w);
	}

	bellmanford_toposort(1);

	for (int i = 1; i <= n; i++) {
		cout << i << ": " << dist[i] << endl;
	}
}