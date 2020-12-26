#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2500 + 5;
const int MOD = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

int memo[MAXN][MAXN];
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) scanf("%*d");

	memo[0][0] = 1;
	for (int u = 1; u <= n; u++) {
		for (int c = 1; c <= k; c++) {
			int op1 = mul(c - 1, memo[u - 1][c]);
			int op2 = mul(c, memo[u - 1][c - 1]);
			memo[u][c] = add(op1, op2);
		}
	}

	printf("%d\n", memo[n][k]);
	return 0;
}