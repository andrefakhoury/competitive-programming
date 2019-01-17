#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXN 105
#define MOD 1000000007

typedef long long ll;

int n, k, d;
ll memo[2][MAXN];

ll dfs(int ed, int w) {
	if (w == n) return ed;
	if (w > n) return 0;

	if (memo[ed][w] != -1) return memo[ed][w];

	ll ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = (dfs(ed || i >= d, w+i)%MOD + ans%MOD)%MOD;
	}
	return memo[ed][w] = ans%MOD;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d%d%d", &n, &k, &d);
	return !printf("%lld\n", dfs(0, 0));
}