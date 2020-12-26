#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int n, f;
vector<pii> edges[MAXN];
vector<pii> edges_sub[MAXN];

ll dist[MAXN];
int parent[MAXN];
bool vis[MAXN];
vector<int> friends;

// void dijkstra(int s) {
// 	memset(dist, -1, sizeof dist);
// 	dist[s] = 0;
// 	priority_queue<pii> pq;
// 	pq.push(mp(0, s));
// 	parent[s] = -1;

// 	while(pq.size()) {
// 		int u = pq.top().second;
// 		pq.pop();
// 		for (int i = 0; i < edges[u].size(); i++) {
// 			int v = edges[u][i].first;
// 			int w = edges[u][i].second;
// 			if (dist[v] == -1 || dist[v] <= dist[u] + w) {
// 				dist[v] = dist[u] + w;
// 				pq.push(mp(-w, v));
// 				parent[v] = u;
// 			}
// 		}
// 	}
// }

void dfs(int u, ll cur) {
	dist[u] = cur;

	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i].first;
		int w = edges[u][i].second;
		parent[v] = u;
		dfs(v, dist[u] + w);
	}
}

void clear_edge(int u) {
	if (u == 1) return;

	for (int i = 0; i < edges_sub[u].size(); i++) {
		if (edges_sub[u][i].first == parent[u]) {
			edges_sub[u][i].second = 0;
			clear_edge(edges_sub[u][i].first);
			return;
		}
	}
}

ll getSum(int u) {
	if (u <= 0 || u > n) return 0;

	if (u == 1) return 0;
	if (vis[u]) return 0;

	vis[u] = true;

	ll ret = 0;
	for (int i = 0; i < edges_sub[u].size(); i++) {
		int v = edges_sub[u][i].first;
		int w = edges_sub[u][i].second;

		if (v == parent[u]) {
			ret += w;
			if (!vis[v]) ret += getSum(v);

			return ret;
		}
	}

	return ret;
}

int main() {

	while(~scanf("%d %d", &n, &f)) {

		for (int i = 1; i <= n-1; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			edges[a].pb(mp(b, c));
			edges_sub[b].pb(mp(a, c));
		}

		for (int i = 0; i < f; i++) {
			int x; scanf("%d", &x);
			friends.pb(x);
		}

		dfs(1, 0);
		// for (int i = 1; i <= n; i++) printf("%d ", dist[i]);

		int max_amigo = friends[0];
		for (int i = 1; i < friends.size(); i++) {
			if (dist[max_amigo] < dist[friends[i]])
				max_amigo = friends[i];
		}
		clear_edge(max_amigo);

		ll ans = 0;
		for (int i = 0; i < friends.size(); i++)
			ans += getSum(friends[i]);

		printf("%lld\n", ans);

		for (int i = 1; i <= n; i++) {
			edges[i].clear();
			edges_sub[i].clear();
		}
		memset(parent, 0, sizeof parent);
		memset(dist, 0, sizeof parent);
		memset(vis, 0, sizeof vis);
		friends.clear();
	}
}