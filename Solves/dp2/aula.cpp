/*
	DP:
		Sub-estrutura otima
		Sobreposicao de problemas
*/

//LCS
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

int a[MAXN], b[MAXN], dp[2][MAXN];
int tamA, tamB;


int lcs() { //MEMORY TRICK -> EM VEZ DE DP[MAXN][MAXN] VAI SER
			//							DP[   2][MAXN]
	for (int i = 0; i <= tamA; i++) dp[i][0] = 0;
	for (int i = 0; i <= tamB; i++) dp[0][i] = 0;

	for (int i = 1; i <= tamA; i++) {
		for (int j = 1; j <= tamB; j++) {
			if (a[i] == b[j]) {
				dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
			} else {
				dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
			}
		}
	}
}

int main() {
	scanf("%d%d", &tamA, &tamB);
	a[0] = b[0] = 0;
	for (int i = 1; i <= tamA; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= tamB; i++)
		scanf("%d", &b[i]);
}

//marcar ou nao marcar

vector<int> edges[MAXN];
int dp[MAXN][2];

int f(int u, int mark) {
	if (dp[u][mark] != -1) return dp[u][mark];
	dp[u][mark] = mark;
	if (!mark) {
		for (auto v : edges[u]) //childrens do v
			dp[u][mark] += f(v, 1);
	} else {
		for (auto v : edges[u]) //childrens do v
			dp[u][mark] += min(f(v, 0), f(v, 1));
	}
	return dp[u][mark];
}

//////////////////////

int universe = (1<<n) -1;

int f(int u, int mask) {
	if (dp[u][mask] != -1) return dp[u][mask];
	if (mask == universe) return 1;
	for (auto v : adj[u]) {
		if ((1<<v)&mask == 0) {
			dp[u][mask] |= f(v, (1<<v)|mask);
		}
	}
	return dp[u][mask];
}

//////