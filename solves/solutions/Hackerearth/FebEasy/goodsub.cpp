#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int freq[30];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;

	string s;
	while (t--) {
		memset(freq, 0, sizeof freq);

		cin >> s;
		sort(s.begin(), s.end());
		for (char c : s) freq[c - 'a']++;

		long long pos = 1;
		for (int i = 0; i < 26; i++) {
			if (freq[i] == 0) continue;
			pos = (pos * freq[i]) % MOD;
		}

		cout << pos << '\n';
	}
}