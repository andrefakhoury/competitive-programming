#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 300015, MOD = 998244353;

ll pot[MAXN];
int color[MAXN];
vector<int> edges[MAXN];
bool imp;

pii dfs(int u, int at) {
	pii ans = mp(0, 1);
	color[u] = at;

	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];

		if (color[v] == at) imp = true;
		else if (color[v] == 0) {
			pii cur = dfs(v, 3 - at);
			
			ans.first  += cur.first;
			ans.second += cur.second;
		}
	}

	if (color[u] == 1) ans.first++;

	return ans;
}

int main() {
	pot[0] = 1;
	for(int i = 1; i < MAXN; i++) pot[i] = (pot[i-1] * 2)%MOD;

	int t; scanf("%d", &t);

	while(t--) {
		int n, m, u, v;
		scanf("%d%d", &n, &m);

		for(int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			edges[u].pb(v);
			edges[v].pb(u);
		}

		imp = false;

		ll ans = 1;
		for(int i = 1; i <= n; i++) {
			if(color[i] == 0) {
				pii cur = dfs(i, 1);
				ll sum = (pot[cur.first] + pot[cur.second - cur.first])%MOD; 
				if (imp) sum = 0;
				ans = (ans * sum)%MOD; 
			}
		}

		printf("%lld\n", ans);

		for(int i = 1; i <= n; i++) {
			edges[i].clear();
			color[i] = 0;
		}
	}
}