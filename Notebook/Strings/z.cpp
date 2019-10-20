#include <bits/stdc++.h>
using namespace std;

vector<int> build_z(string& s) {
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

void imp() {
	cout << "Just a legend\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	int n = s.size();

	s = s + "#" + s;
	cout << s << endl;

	vector<int> z = build_z(s);

	for (int i : z) cout << i << ' ';
	cout << endl;

	// vector<int> p;
	// for (int i = n-1; i >= 0; i--) {
	// 	if (i + z[i] == n) p.push_back(i);
	// }

	// if (p.empty()) imp();

	// reverse(p.begin(), p.end());

	// int ans = 0;
	// for (int i = 0; i < n; i++) {
	// 	if (z[i] == 0) continue;

	// 	int cur = lower_bound(p.begin(), p.end(), i + z[i]) - p.begin();
	// 	cur -= 

	// 	ans = max(ans, cur);
	// }

	// if (!ans) imp();
	// for (int j = 0, i = n - ans; i < n; i++, j++)
	// 	if (s[i] != s[j]) imp();

	// for (int i = 0; i < ans; i++) cout << s[i];
	// cout << endl;
}