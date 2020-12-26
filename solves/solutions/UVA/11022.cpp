#include <bits/stdc++.h>
using namespace std;

vector<int> build_z(string& s, int L, int R) {
	int n = R - L;

	vector<int> z(n, 0);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);

		while(i + z[i] < n && s[z[i]+i+L] == s[L + z[i]])
			z[i]++;

		if (z[i] + i - 1 > r)
			l = i, r = i + z[i] - 1;
	}

	return z;
}

int memo[81][81];
int solve(string& s, int i, int j) {
	int& ret = memo[i][j];
	if (~ret) return ret;
	if (i == j) return ret = 1;
	if (i > j) return ret = 0;

	vector<int> z = build_z(s, i, j+1);

	int ans = j - i + 1;
	for (int c = 1; c < ans; c++) {
		if (ans%c == 0 && z[c] + c == ans) ans = c;
	}

	if (i + ans - 1 != j) ans = min(ans, solve(s, i, i + ans - 1));

	for (int x = 1; j - x >= i; x++) {
		ans = min(ans, x + solve(s, i, j-x));
		ans = min(ans, x + solve(s, i+x, j));
		ans = min(ans, solve(s, i, j-x) + solve(s, j-x+1, j));
	}

	return ret = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;

	while(cin >> s, s != "*") {
		memset(memo, -1, sizeof memo);

		int n = s.size();
		vector<int> z = build_z(s, 0, n);

		cout << solve(s, 0, n-1) << '\n';
	}
}