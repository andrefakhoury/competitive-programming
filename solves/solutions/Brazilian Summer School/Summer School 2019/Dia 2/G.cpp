#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
typedef long long ll;

ll col[MAXN][MAXN], n, sum[MAXN][MAXN], best[MAXN][MAXN];

int main() {
	while(scanf("%lld", &n), n != 0) {
		memset(col, 0, sizeof col);
		memset(sum, 0, sizeof sum);
		memset(best, 0, sizeof best);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				scanf("%lld", &col[i-j+1][j]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n-i+1; j++)
				sum[i][j] = sum[i][j-1] + col[i][j];

		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n-i+1; j++) {
				ll toSum = best[i-1][j];

				for (int k = j; k <= n-i+2; k++) {
					toSum = max(toSum, best[i-1][k]);
				}

				best[i][j] = sum[i][j] + toSum;
				ans = max(ans, best[i][j]);
			}
		}

		printf("%lld\n", ans);
	}
}
