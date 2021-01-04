#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long ll;

int a[51];
ll memo[51][251];

ll solve(int i, int cur, int n, int m) {
	if (cur > n) return 0;
	if (i > m) return cur == n;

	ll& ret = memo[i][cur];
	if (~ret) return ret;

	return ret = solve(i, cur+a[i], n, m) + solve(i+1, cur, n, m);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", a+i);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(1, 0, n, m));
}