#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, int> pii;
const int MAXN = 100005;
const ll INF = 1000000000000LL;

vector<pii> edges[MAXN];

bool bfelse(int n, vector<ll> &dist, vector<int> &pred) {
	dist.assign(n+1, INF);
	pred.assign(n+1, -1);

	priority_queue<pii> pq;

	dist[1] = 0;
	pq.push(mp(0, 1));

	while(pq.size()) {
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < edges[u].size(); i++) {
			int v = edges[u][i].first, w = edges[u][i].second;
			if (dist[u]+w < dist[v]) {
				dist[v] = dist[u] + w;
				pred[v] = u;
				pq.push(mp(-dist[v], v));
			}
		}
	}

	return dist[n] != INF;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int u, v, w;
	vector<int> pred;
	vector<ll> dist;

	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		edges[u].pb(mp(v, w));
		edges[v].pb(mp(u, w));
	}

	if (bfelse(n, dist, pred)) {
		vector<int> ans;
		for (int i = n; i != 1; i = pred[i]) ans.pb(i); ans.pb(1);
		for (int i = ans.size()-1; i >= 0; i--) printf("%d ", ans[i]);
		printf("\n");
	} else printf("-1\n");

	return 0;
}