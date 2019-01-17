#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], b[MAXN];
int memo[MAXN][6][6][6];


int solve(int i, int l, int r, int dif) {
	if (l < 1 || l > 5 || r < 1 || r > 5) return -1;
	if (i > n) return 0;
	if (i == n) return b[i] = l != dif ? l : r != dif ? r : -1;

	if (memo[i][l][r][dif]) return memo[i][l][r][dif];

	int ans = -1, m;
	for (m = l; m <= r; m++) {
		if (m == dif) continue;

		if (a[i] <  a[i+1]) ans = solve(i+1, m+1, 5, 0);
		if (a[i] >  a[i+1]) ans = solve(i+1, 1, m-1, 0);
		if (a[i] == a[i+1]) ans = solve(i+1, 1, 5, m);

		if (ans != -1) break;
	}

	return memo[i][l][r][dif] = b[i] = m > r ? -1 : m;
}




int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	solve(1, 1, 5, 0);
	for (int i = 1; i <= n; i++) if (b[i] == -1) return !printf("-1\n");
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
}