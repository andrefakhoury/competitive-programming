#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		int n; cin >> n;
		string s; cin >> s;

		string ans;
		for (char c : s)
			ans += c == 'E' ? 'S' : 'E';

		cout << "Case #" << cs << ": " << ans << "\n";
	}
}