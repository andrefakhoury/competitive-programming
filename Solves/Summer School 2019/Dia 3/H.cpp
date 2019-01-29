#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const ll INF = 100000000000000LL;

ll memo[40][40][60];

ll solve(int n, int m, int k) {
	if (memo[n][m][k] != -1) return memo[n][m][k];
	if (n * m == k || k == 0) return memo[n][m][k] = 0;
	if (k > n * m) return memo[n][m][k] = INF;

	ll H = INF, W = INF;

	for (int i = 1; i <= n-1; i++) {
		for (int _k = 0; _k <= k; _k++)
			H = min(H, solve(n-i, m, _k) + solve(i, m, k - _k) + m*m);
	}

	for (int i = 1; i <= m-1; i++) {
		for (int _k = 0; _k <= k; _k++)
			W = min(W, solve(n, m-i, _k) + solve(n, i, k - _k) + n*n);
	}

	return memo[n][m][k] = min(H, W);
}

int main() {
	int t; scanf("%d", &t);
	memset(memo, -1, sizeof memo);

	while(t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		printf("%lld\n", solve(n, m, k));
	}

	return 0;
}