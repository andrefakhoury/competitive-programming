#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int solve(string& a, string& b, string& c) {
	string s = a + "#" + b;
	int n = s.size(), ans1, ans2;
	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && s[pi[i]] != s[i])
			pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;
	}

	for (int i = 1; i < n; i++) if (pi[i] == a.size()) {
		ans1 = a.size();
		s = b + "#" + c;
		goto find;
	}

	ans1 = pi[n-1];

	s = b + a.substr(pi[n-1], a.size()) + "#" + c;

	find:
	n = s.size();
	pi = vector<int>(n);

	for (int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && s[pi[i]] != s[i])
			pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;
	}

	ans2 = pi[n-1];

	return a.size() + b.size() + c.size() - ans1 - ans2;
}

int main () {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b, c;
	while(cin >> a >> b >> c) {
		int ans = min({solve(a, b, c),
					   solve(a, c, b),
					   solve(b, a, c),
					   solve(b, c, a),
					   solve(c, a, b),
					   solve(c, b, a)});
		cout << ans << '\n';
	}

	return 0;
}