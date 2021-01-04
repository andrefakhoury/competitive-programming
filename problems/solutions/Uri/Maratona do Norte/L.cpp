#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int k; cin >> k;
	string s; cin >> s;

	vector<map<char, int> > freq(k);

	int n; cin >> n;
	while(n--) {
		string t; cin >> t;
		for (int i = 0; i < k; i++) {
			freq[i][t[i]]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		int best = 0;
		for (int j = 'A'; j <= 'Z'; j++) {
			if (j == s[i]) continue;
			best = max(best, freq[i][j]);
		}
		ans += best;
	}

	cout << ans << endl;
}