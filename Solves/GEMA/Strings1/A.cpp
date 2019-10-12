#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		string t, p; cin >> t >> p;

		string s = p + "#" + t;
		int n = s.size(), m = p.size();
		vector<int> z(n, 0);
		for (int i = 1, l = 0, r = 0; i < n; i++) {
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);

			while(i + z[i] < n && s[z[i]+i] == s[z[i]])
				z[i]++;

			if (z[i] + i - 1 > r)
				l = i, r = i + z[i] - 1;
		}

		vector<int> ans;
		for (int i = m+1; i < n; i++) {
			if (z[i] == m) ans.push_back(i - m);
		}

		if (ans.empty()) cout << "Not Found\n";
		else {
			cout << ans.size() << "\n";
			for (int i : ans) cout << i << " ";
			cout << "\n";
		}

		if (T) cout << "\n";

	}
}