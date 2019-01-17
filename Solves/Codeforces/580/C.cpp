#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010
#define pb push_back

vector<int> edges[MAXN];

int cat[MAXN], vis[MAXN];
int n, m;

int dfs(int u, int qt) {
	int aa = qt;
	vis[u] = 1;
	qt = (cat[u]) ? qt+1 : 0;

	if (qt > m) return 0;
	int ans = 0, leaf = 0;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!vis[v]) {
			ans += dfs(v, qt);
			leaf++;
		}
	}

	return leaf ? ans : 1;
}

int main() {
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", cat+i);
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &a, &b);
		edges[a].pb(b);
		edges[b].pb(a);
	}

	printf("%d\n", dfs(1, 0));
	return 0;

}