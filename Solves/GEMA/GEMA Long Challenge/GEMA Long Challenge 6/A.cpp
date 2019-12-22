#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e3 + 5;

int mat[MAXN][MAXN];
int sum[MAXN][MAXN];

int qtt(int i, int j, int tam) {
	if (tam == 0) return 0;
	return sum[i+tam-1][j+tam-1] - sum[i+tam-1][j-1] - sum[i-1][j+tam-1] + sum[i-1][j-1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m, q, k; cin >> n >> m >> q >> k;

	for (int i = 1; i <= q; i++) {
		int I, J; cin >> I >> J;
		mat[I][J] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i][j];

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int lo = 1, hi = min(n-i+1, m-j+1), mi, ans = -1;
			while(lo < hi) {
				mi = (lo + hi) / 2;
				if (qtt(i, j, mi) >= k) hi = mi-1, ans = mi;
				else lo = mi+1;
			}
			
		}
	}

	cout << ans << endl;
	return 0;
}