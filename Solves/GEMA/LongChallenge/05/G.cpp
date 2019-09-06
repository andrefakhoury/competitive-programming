#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int color[MAXN];
vector<int> edges[MAXN];
vector<pii> query[MAXN];
vector<int> ans;
bool vis[MAXN];

map<int, int> dfs(int u) {
	vis[u] = true;
	map<int, int> ret;
	ret[color[u]]++;

	map<int, int> fcur;
	for (int v : edges[u]) {
		if (vis[v]) continue;
		map<int, int> cur = dfs(v);
		for (auto g : cur) ret[g.fi] += g.se;
	}

	vector<int> curAns;
	for (auto x : ret) curAns.pb(x.se);
	sort(curAns.begin(), curAns.end());

	for (auto p : query[u]) {
		ans[p.se] = curAns.end() - lower_bound(curAns.begin(), curAns.end(), p.fi);
	}

	return ret;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", color+i);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	ans.resize(m);
	for (int i = 0; i < m; i++) {
		int v, k; scanf("%d%d", &v, &k);
		query[v].emplace_back(k, i);
	}

	for (int i = 1; i <= n; i++) {
		sort(query[i].begin(), query[i].end());
	}

	dfs(1);

	for (int i : ans) printf("%d\n", i);
	return 0;	
}