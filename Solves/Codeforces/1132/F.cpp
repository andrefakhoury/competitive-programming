#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 505;

int memo[MAXN][MAXN], n;
string s;

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;

	if (memo[l][r] != -1) return memo[l][r];

	int ret = 1 + solve(l+1, r);

	for (int i = l+1; i <= r; i++)
		if (s[l] == s[i])
			ret = min(ret, solve(l, i-1) + solve(i+1, r));

	return memo[l][r] = ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	memset(memo, -1, sizeof memo);

	cin >> n >> s;
	cout << solve(0, n-1) << endl;

	return 0;
}