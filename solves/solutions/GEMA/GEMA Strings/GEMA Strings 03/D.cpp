#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD[2] = {1000000007, 1000000009};
const int P[2] = {31, 37};

int H1[2][MAXN], H2[2][MAXN];
int curPow[2][MAXN], invPow[2][MAXN];

char s1[MAXN], s2[MAXN];
int n1, n2;

inline ll fastExp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

bool menor(int I1, int I2) {
	if (s1[I1] != s2[I2]) return s1[I1] < s2[I2];

	int lo = 0, hi = min(n1-I1+1, n2-I2+1), mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;

		int C1[2], C2[2];
		for (int j = 0; j < 2; j++) {
			C1[j] = (H1[j][I1+mi-1] - H1[j][I1-1] + MOD[j]) % MOD[j];
			C1[j] = (C1[j] * ll(invPow[j][I1-1])) % MOD[j];

			C2[j] = (H2[j][I2+mi-1] - H2[j][I2-1] + MOD[j]) % MOD[j];
			C2[j] = (C2[j] * ll(invPow[j][I2-1])) % MOD[j];
		}

		if (C1[0] == C2[0] && C1[1] == C2[1]) lo = mi;
		else hi = mi-1;
	}

	printf("%d:%d = %d\n", I1, I2, lo);

	return s1[I1+lo] <= s2[I2+lo];
}

int main() {
	for (int k = 0; k < 2; k++) {
		H1[k][0] = H2[k][0] = 0;
		curPow[k][0] = invPow[k][0] = 1;
	}

	for (int i = 1; i < MAXN; i++) for (int k = 0; k < 2; k++) {
		curPow[k][i] = (ll(curPow[k][i-1]) * P[k]) % MOD[k];
		invPow[k][i] = fastExp(curPow[k][i], MOD[k]-2, MOD[k]);	
	}

	int t; scanf("%d", &t);
	while(t--) {
		scanf(" %s %s", s1+1, s2+1);
		n1 = strlen(s1+1), n2 = strlen(s2+1);

		for (int i = 1; i <= n1; i++) for (int k = 0; k < 2; k++)
			H1[k][i] = (H1[k][i-1] + ll(curPow[k][i-1]) * (s1[i] - 'A' + 1)) % MOD[k];

		for (int i = 1; i <= n2; i++) for (int k = 0; k < 2; k++)
			H2[k][i] = (H2[k][i-1] + ll(curPow[k][i-1]) * (s2[i] - 'A' + 1)) % MOD[k];

		int I1 = 1, I2 = 1;
		for (int i = 1; i <= n1 + n2; i++) {
			char ans;

			if (I1 > n1) ans = s2[I2++];
			else if (I2 > n2) ans = s1[I1++];
			else if (menor(I1, I2)) ans = s1[I1++];
			else ans = s2[I2++];

			printf("[%c]\n", ans);
		}

		printf("\n");
	}

	return 0;
}