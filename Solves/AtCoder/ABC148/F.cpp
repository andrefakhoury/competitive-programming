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
const int MAXN = 1e5 + 5;
const int MAXL = 21;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> edges[MAXN];
int distA[MAXN];
int distB[MAXN];

void dfs_dist(int u, int p, int d, int* dist) {
	dist[u] = d;
	for (int v : edges[u]) if (v != p) dfs_dist(v, u, d + 1, dist);
}

inline int solve(int a, int b, int n) {
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		if (distA[i] < distB[i]) {
			ans = max(ans, distB[i]);
		}
	}

	return ans - 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b; cin >> n >> a >> b;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}

	dfs_dist(a, a, 0, distA);
	dfs_dist(b, b, 0, distB);
	int ans = solve(a, b, n);

	printf("%d\n", ans);
	return 0;
}