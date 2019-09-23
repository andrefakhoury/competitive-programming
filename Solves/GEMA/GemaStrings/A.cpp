#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int MOD[2] = {1000000007, 1000000009};
const int P[2] = {31, 37};

int Hash[2][MAXN], curPow[2][MAXN];
char s[MAXN];
int n;

bool cmp(int const& A, int const& B) {
	int lo = 0, hi = n-1, mi;
	int curA, curB;
	bool check;

	while(lo < hi) {
		mi = (lo + hi + 1) / 2;

		check = true;
		for (int k = 0; check && k < 2; k++) {
			curA = ((Hash[k][A + mi - 1] - Hash[k][A - 1]) % MOD[k] + MOD[k]) % MOD[k];
			curB = ((Hash[k][B + mi - 1] - Hash[k][B - 1]) % MOD[k] + MOD[k]) % MOD[k];

			if (A < B) curA = (curA * ll(curPow[k][B - A])) % MOD[k];
			else	   curB = (curB * ll(curPow[k][A - B])) % MOD[k];

			check &= curA == curB;
		}

		if (check) lo = mi;
		else hi = mi-1;
	}

	return (s[A+lo] == s[B+lo]) ? (A < B) : (s[A+lo] < s[B+lo]);
}

int main() {
	scanf(" %s", s+1);
	n = strlen(s+1);

	for (int i = 1; i <= n; i++) s[i+n] = s[i];

	for (int k = 0; k < 2; k++) {
		Hash[k][0] = 0;
		curPow[k][0] = 1;
	}

	for (int i = 1; i <= 2 * n; i++) {
		for (int k = 0; k < 2; k++) {
			Hash[k][i] = (Hash[k][i-1] + ll(curPow[k][i-1]) * (s[i] - 'a' + 1)) % MOD[k];
			curPow[k][i] = (ll(curPow[k][i-1]) * P[k]) % MOD[k];
		}
	}

	int ans = 1;
	for (int i = 2; i <= n; i++) if (cmp(i, ans)) ans = i;

	printf("%d\n", ans - 1);

	return 0;
}