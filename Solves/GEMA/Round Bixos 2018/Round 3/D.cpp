#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 1005
#define MAXM 1005

//ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> edges[MAXN];
int vis[MAXN];

void dfs(int u, int ign) {
	if (u == ign) return;
	
	vis[u] = 1;
	for(int i = 0; i < edges[u].size(); i++) {
		if(vis[edges[u][i]] == 0) dfs(edges[u][i], ign);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	int x, y;
	
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		edges[x].pb(y);
		edges[y].pb(x);
	}
	
	int ans, best = 0;
	for (int ign = 0; ign <= n; ign++) {
		mset(vis, 0);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i != ign && !vis[i]) {
				dfs(i, ign);
				ans++;
			}
		}
		best = max(best, ans);
	}
	
	printf("%d\n", best);	
	
	return 0;
}