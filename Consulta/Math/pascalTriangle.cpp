#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005, MOD = 1000000007;
long long nck[MAXN][MAXN];

void pascal(int N) {
	for (int i = 0; i <= N; i++) nck[i][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			nck[i][j] = (nck[i-1][j-1] + nck[i-1][j])%MOD;
}