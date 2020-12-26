#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e6 + 5;
const int MOD[2] = {1000000007, 1000000009};
const int P[2] = {131, 131};

int H1[2][MAXN], H2[2][MAXN];
int curPow[2][MAXN], invPow[2][MAXN];

char s1[MAXN], s2[MAXN];
int v1[MAXN], v2[MAXN];

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

struct HASH{
	size_t operator()(const pair<int,int>&x)const{
		return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
	}
};

inline bool check(int k) {
	unordered_set<pii, HASH> st;

	for (int i = 1; i <= n1-k+1; i++) {
		int cur[2];
		for (int j = 0; j < 2; j++) {
			cur[j] = (H1[j][i+k-1] - H1[j][i-1] + MOD[j]) % MOD[j];
			cur[j] = (cur[j] * ll(invPow[j][i-1])) % MOD[j];
		}

		st.emplace(cur[0], cur[1]);
	}

	for (int i = 1; i <= n2-k+1; i++) {
		int cur[2];
		for (int j = 0; j < 2; j++) {
			cur[j] = (H2[j][i+k-1] - H2[j][i-1] + MOD[j]) % MOD[j];
			cur[j] = (cur[j] * ll(invPow[j][i-1])) % MOD[j];
		}

		if (st.count({cur[0], cur[1]})) return true;
	}

	return false;
}

inline int corr(char c) {
	return c;
}

int main() {
	scanf(" %s %s", s1+1, s2+1);
	n1 = strlen(s1+1), n2 = strlen(s2+1);

	for (int i = 1; i <= n1; i++) v1[i] = corr(s1[i]);
	for (int i = 1; i <= n2; i++) v2[i] = corr(s2[i]);
	if  (n1 > n2) {
		for (int i = 1; i <= max(n1, n2); i++) swap(v1[i], v2[i]);
		swap(n1, n2);
	}

	for (int k = 0; k < 2; k++) {
		H1[k][0] = H2[k][0] = 0;
		curPow[k][0] = invPow[k][0] = 1;
	}

	for (int i = 1; i <= max(n1, n2); i++) for (int k = 0; k < 2; k++) {
		curPow[k][i] = (ll(curPow[k][i-1]) * P[k]) % MOD[k];
		invPow[k][i] = fastExp(curPow[k][i], MOD[k]-2, MOD[k]);	
	}

	for (int i = 1; i <= n1; i++) for (int k = 0; k < 2; k++)
		H1[k][i] = (H1[k][i-1] + ll(curPow[k][i-1]) * v1[i]) % MOD[k];

	for (int i = 1; i <= n2; i++) for (int k = 0; k < 2; k++)
		H2[k][i] = (H2[k][i-1] + ll(curPow[k][i-1]) * v2[i]) % MOD[k];

	int lo = 0, hi = min(n1, n2), mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(mi)) lo = mi;
		else hi = mi-1;
	}

	printf("%d\n", lo);
	return 0;
}