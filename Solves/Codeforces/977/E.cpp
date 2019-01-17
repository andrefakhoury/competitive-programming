#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
#define MAXN 200010

vector<int> edges[MAXN];
int a[MAXN];

int flag;

bool vis[MAXN];
void dfs(int u) {
	if (a[u] != 2) flag = 1;
	vis[u] = 1;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		if (!vis[edges[u][i]]) dfs(edges[u][i]);
	}
}

int main() {
	int n, m, x, y; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		edges[x].pb(y);
		edges[y].pb(x);
		a[x]++; a[y]++;
	}
	if (n < 3) return !printf("0");

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		flag = 0;
		if (!vis[i] && a[i] == 2) {
			dfs(i);
			if (!flag) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}