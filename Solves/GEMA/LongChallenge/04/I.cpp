#include <bits/stdc++.h>
using namespace std;

string s, t, crypto;
int n;

int solve() {
	string x = t;
	for (char& c : x) c = crypto[c-'a'];

	int ret = INT_MAX;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++)
			cur += s[i+j] != x[j];
		ret = min(ret, cur);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> s >> t;
	crypto = "ABCDE";

	n = s.size();
	s += s;

	int ans = INT_MAX;
	do {
		ans = min(ans, solve());
	} while(next_permutation(crypto.begin(), crypto.end()));

	cout << ans << '\n';
}