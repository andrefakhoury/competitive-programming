#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define MAXQ 200005

typedef long long ll;

int ver[MAXN], dp[MAXN][MAXN], ans, l, r;

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", ver+i);

	ll somacc;
	for (int i = n; i >= 1; i--) {
		ans = 0;
		somacc = ver[i];
		for (int j = i+1; j <= n; j++) {
			somacc += ver[j];
			if (!somacc) ans++;
			dp[i][j] = dp[j][i] = ans;
		}
	}

	while(q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l][r]);
	}
	return 0;
}