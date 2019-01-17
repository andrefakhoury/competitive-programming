#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 100005, INF = INT_MAX;
vector<pair<int, int> > edges[MAXN];
int a[MAXN], flour[MAXN];

int minimum(int k) {
	int res = INF;
	for (int i = 0; i < edges[k].size(); i++) {
		int v = edges[k][i].first, w = edges[k][i].second;
		if (!flour[v]) res = min(res, w);
	}
	return res;
}

int main() {
	int n, m, k; cin >> n >> m >> k;
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		edges[u].pb(mp(v, w));
		edges[v].pb(mp(u, w));
	}

	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		flour[a[i]] = 1;
	}

	int ans = INF;
	for (int i = 1; i <= k; i++) {
		ans = min(ans, minimum(a[i]));
	}

	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}