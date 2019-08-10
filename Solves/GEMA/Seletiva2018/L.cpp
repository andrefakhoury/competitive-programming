#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define fastcin ios::sync_with_stdio(false);
#define endl "\n"

#define MAXN 500020


vector<int> edges[MAXN];
int vis[MAXN];

int dfs(int u) {
	int ans = 0;
	vis[u] = 1;
	for(int i = 0; i < edges[u].size(); ++i) {
		if(!vis[edges[u][i]])
			ans = max(ans, dfs(edges[u][i]));
	}
	return 1+ans;
}

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	int n, A, u, v; scanf("%d%d", &n, &A);
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	printf("%d\n", dfs(A));
	return 0;	
}