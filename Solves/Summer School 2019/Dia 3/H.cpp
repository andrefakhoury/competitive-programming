#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 100000000000000LL;

ll memo[35][35][55];

ll solve(int n, int m, int k) {
	if (k < 0) return INF;

	ll &ret = memo[n][m][k];
	if (~ret) return ret;

	if (n * m == k || k == 0) return ret = 0;
	if (k > n * m) return ret = INF;

	ret = INF;
	for (int i = 1; i < n; i++) {
		ret = min(ret, m * m + solve(i, m, k));
		ret = min(ret, m * m + solve(n-i, m, k - i * m));
	}
 
	for (int i = 1; i < m; i++) {
		ret = min(ret, n * n + solve(n, i, k));
		ret = min(ret, n * n + solve(n, m-i, k - i * n));
	}
	
	return ret;
}

int main() {
	memset(memo, -1, sizeof memo);

	int t; scanf("%d", &t);

	while(t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		printf("%lld\n", solve(n, m, k));
	}

	return 0;
}