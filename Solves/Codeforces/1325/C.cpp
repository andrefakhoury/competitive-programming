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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pii> edges[MAXN];
int ans[MAXN];

int leaf = -1;
vector<int> yet;

void dfs(int u, int p, int ind) {
	int cnt = 0;
	for (auto e : edges[u]) if (e.fi != p) {
		cnt++;
		dfs(e.fi, u, e.se);
	}

	if (cnt == 0) ans[ind] = ++leaf;
	else yet.pb(ind);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	int r = 1;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		edges[u].eb(v, i);
		edges[v].eb(u, i);

		if (edges[u].size() > 1) r = u;
		if (edges[v].size() > 1) r = v;
	}

	dfs(r, -1, 0);
	for (int x : yet) if (x > 0) ans[x] = ++leaf;

	for (int i = 1; i < n; i++) cout << ans[i] << '\n';

	return 0;
}