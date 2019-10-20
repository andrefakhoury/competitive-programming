#include <bits/stdc++.h>
using namespace std;

vector<int> build_Z(string& s) {
	int n = s.size();
	vector<int> z(n, 0);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);

		while(i + z[i] < n && s[z[i]+i] == s[z[i]])
			z[i]++;

		if (z[i] + i - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s;
	while(cin >> s) {
		int n = s.size();

		string t = s;
		reverse(t.begin(), t.end());

		string y = t + "#" + s;
		vector<int> z = build_Z(y);

		int ans = n;
		for (int i = n + 1; i < 2 * n + 1; i++) {
			if (z[i] + i - n - 1 == n)
				ans = min(ans, n - z[i]);
		}

		string S;
		for (int i = 0; i < ans; i++) S.push_back(s[i]);
		reverse(S.begin(), S.end());

		S = s + S;

		cout << S << '\n';
	}
}