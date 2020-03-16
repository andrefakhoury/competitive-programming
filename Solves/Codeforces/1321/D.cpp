#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> edges[MAXN];
vector<int> rev[MAXN];
vector<int> same[MAXN];

int dist[MAXN];
inline void bfs(int s) {
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.emplace(s);
	dist[s] = 0;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int v : rev[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.emplace(v);
			}

			if (dist[v] == dist[u] + 1) same[v].eb(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		edges[u].pb(v);
		rev[v].pb(u);
	}

	int k; cin >> k;
	vector<int> a(k);
	for (int& i : a) cin >> i;

	bfs(a[k-1]);

	pii ans = {0, 0};
	for (int i = 1; i < k; i++) {
		if (dist[a[i]] == dist[a[i-1]] - 1) {
			if (same[a[i-1]].size() > 1) ans.se += 1;
		} else {
			ans.fi += 1;
			ans.se += 1;
		}
	}

	cout << ans.fi << ' ' << ans.se << '\n';

	return 0;
}