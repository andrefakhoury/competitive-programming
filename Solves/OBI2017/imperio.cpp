#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define pb push_back

vector<int> edges[MAXN];

int vis[MAXN];

int n, ans = 0x3f3f3f3f;

int dfs(int u) {
	int count = 1;
	vis[u] = 1;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		int& v = edges[u][i];
		if (!vis[v]) count += dfs(v);
	}
	ans = min(ans, abs(n-2*count));
	return count;
}

int main() {
	int x, y; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		edges[x].pb(y);
		edges[y].pb(x);
	}

	dfs(1);
	printf("%d\n", ans);
	return 0;
}