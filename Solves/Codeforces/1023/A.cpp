#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;

	if (n-m > 1) {
		cout << "NO\n";
		return 0;
	}

	if (s.find("*") == string::npos && n != m) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == "*") break;
		if (s[i] != t[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	for (int i = n-1, j = m-1; i >= 0; i--, j--) {
		if (s[i] == "*") break;
		if (s[i] != t[j]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}