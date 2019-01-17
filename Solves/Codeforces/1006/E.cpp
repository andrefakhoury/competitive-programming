#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
#define pb push_back
#define mp make_pair
#define mset(x, y) memset((x), (y), sizeof(x))

vector<int> edges[MAXN];
int vis[MAXN], qtt[MAXN], pos[MAXN], cnt;
vector<int> l;

int dfs(int u) {
	l.pb(u);
	pos[u] = cnt++;
	vis[u] = 1;

	qtt[u] = 1;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!vis[v]) qtt[u] += dfs(v);
	}
	return qtt[u];
}

int main() {
	int n, q, u, k, ans, x;
	scanf("%d%d", &n, &q);

	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		edges[x].pb(i);
	}

	l.pb(0);
	dfs(1);

	while(q--) {
		scanf("%d%d", &u, &k);
		if (qtt[u] < k) ans = -1;
		else ans = l[pos[u]+k];
		printf("%d\n", ans);
	}

}
