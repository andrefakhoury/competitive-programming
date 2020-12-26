#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 500005;

vector<int> edges[MAXN];
bool vis[MAXN];
double ans = 0;

void dfs(int u, int dist, double prob) {
	vis[u] = true;

	int qtt = 0;
	for (auto v : edges[u]) qtt += !vis[v];

	if (qtt == 0) {
		ans += prob * dist;
		return;
	}

	for (auto v : edges[u]) {
		if (!vis[v]) dfs(v, dist + 1, prob * (1.0 / qtt));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	for (int i = 1; i <= n-1; i++) {
		int u, v; cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}

	dfs(1, 0, 1.0);

	cout << fixed << setprecision(10) << ans << endl;
}