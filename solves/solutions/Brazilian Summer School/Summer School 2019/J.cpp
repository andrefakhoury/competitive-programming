#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;
const int MOD[2] = {1000000007, 1000000009};
const int P[2] = {31, 37};

int Hash1[2][MAXN], Hash2[2][MAXN], curPow[2][MAXN], invPow[2][MAXN];
char s1[MAXN], s2[MAXN];
int n, m;

inline int inv(int a, int m) {
	a %= m;
	int b = m - 2;
	
	int res = 1;
	while (b > 0) {
		if (b & 1) res = (ll(res) * a) % m;
		a = (ll(a) * a) % m;
		b >>= 1;
	}

	return res;
}

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

int check(int k) {
	unordered_set<pair<int, int>, HASH> st;

	for (int i = 1; i <= n-k+1; i++) {
		int num0 = ((Hash1[0][i+k-1] - Hash1[0][i-1])%MOD[0] + MOD[0])%MOD[0];
		int num1 = ((Hash1[1][i+k-1] - Hash1[1][i-1])%MOD[1] + MOD[1])%MOD[1];

		num0 = (num0 * ll(invPow[0][i-1])) % MOD[0];
		num1 = (num1 * ll(invPow[1][i-1])) % MOD[1];

		st.insert({num0, num1});
	}

	for (int i = 1; i <= m-k+1; i++) {
		int num0 = ((Hash2[0][i+k-1] - Hash2[0][i-1])%MOD[0] + MOD[0])%MOD[0];
		int num1 = ((Hash2[1][i+k-1] - Hash2[1][i-1])%MOD[1] + MOD[1])%MOD[1];

		num0 = (num0 * ll(invPow[0][i-1])) % MOD[0];
		num1 = (num1 * ll(invPow[1][i-1])) % MOD[1];

		if (st.count({num0, num1})) return i;
	}


	return 0;
}

int main() {
	scanf(" %s", s1+1);
	n = strlen(s1+1);

	scanf(" %s", s2+1);
	m = strlen(s2+1);

	for (int k = 0; k < 2; k++) {
		Hash1[k][0] = 0;
		curPow[k][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 2; k++) {
			Hash1[k][i] = (Hash1[k][i-1] + ll(curPow[k][i-1]) * (s1[i] - 'a' + 1)) % MOD[k];
			curPow[k][i] = (ll(curPow[k][i-1]) * P[k]) % MOD[k];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int k = 0; k < 2; k++) {
			Hash2[k][i] = (Hash2[k][i-1] + ll(curPow[k][i-1]) * (s2[i] - 'a' + 1)) % MOD[k];
			curPow[k][i] = (ll(curPow[k][i-1]) * P[k]) % MOD[k];
		}
	}

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i <= n; i++) {
			invPow[k][i] = inv(curPow[k][i], MOD[k]);
		}
	}

	int lo = 0, hi = m, mi, ans;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;

		int c = check(mi);
		if (c) lo = mi, ans = c;
		else hi = mi-1;
	}

	for (int i = ans; i <= ans + lo - 1; i++) printf("%c", s2[i]);
	if (lo) printf("\n");
	printf("%d\n", lo);
	return 0;
}