#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

#define max(a, b) (a > b ? a : b)

const int MAXN = 300010;

int n, w[MAXN];
vector<pii> edges[MAXN];
bool vis[MAXN];

ll dfs(int u, ll cur) {
	cur += w[u];
	vis[u] = true;

	ll ans = cur;
	ll op  = 0;

	for (int i = 0; i < edges[u].size(); i++) {
		if (vis[edges[u][i].first]) continue;
		op = dfs(edges[u][i].first, max(0, cur - edges[u][i].second));
		ans = max(ans, op);
	}

	return ans;
}

int main() {
	srand(time(NULL));

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n-1; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges[x].pb(mp(y, z));
		edges[y].pb(mp(x, z));
	}

	ll ans = dfs(1, 0), cur;
	int cnt = 100;

	while(cnt--) {
		memset(vis, 0, sizeof(vis));
		cur = dfs(rand()%n + 1, 0);

		ans = max(ans, cur);
	}

	cout << ans << endl;

	return 0;
}