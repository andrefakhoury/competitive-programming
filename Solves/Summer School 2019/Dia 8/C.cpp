#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, c0, d0;
ll a[15], b[15], c[15], d[15];
ll memo[15][1005];

ll solve(int i, ll cur) {
	if (cur < 0) return -9999999;

	if (i > m) return (cur/c0) * d0;
	if (memo[i][cur] != -1) return memo[i][cur];

	ll ret = solve(i+1, cur);
	for (ll k = 1; k <= a[i]/b[i]; k++)
		ret = max(ret, k * d[i] + solve(i+1, cur - k * c[i]));

	return memo[i][cur] = ret;
}

int main() {
	memset(memo, -1, sizeof memo);

	scanf("%lld%lld%lld%lld", &n, &m, &c0, &d0);

	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld%lld", a+i, b+i, c+i, d+i);

	printf("%lld\n", solve(1, n));	
}