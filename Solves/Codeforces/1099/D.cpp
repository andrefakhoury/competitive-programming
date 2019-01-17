#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
ll n, s[MAXN], a[MAXN];

void impossible() {
	printf("-1\n");
	exit(0);
}

void dfs(int u, ll sum) {

	ll men = LLONG_MAX;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		int v = edges[u][i];
		men = min(men, s[v]);
	}

	if (s[u] == -1) {
		a[u] = men - sum;
		if (edges[u].size() == 0) a[u] = 0;
	} else {
		a[u] = s[u] - sum;
	}

	if (a[u] < 0) impossible();

	for (int i = 0; i < (int)edges[u].size(); i++) {
		int v = edges[u][i];
		dfs(v, sum + a[u]);
	}

}


int main() {
	scanf("%lld", &n);
	for (int i = 2; i <= n; i++) {
		int u; scanf("%d", &u);
		edges[u].pb(i);
	}

	for (int i = 1; i <= n; i++) scanf("%lld", s+i);

	dfs(1, 0);

	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i];

	printf("%lld\n", ans);
}
