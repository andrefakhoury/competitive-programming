#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
string s;

pii check(int start, string& t, int l, int r) {
	for (int i = start; i < s.size() - (r - l) + 1; i++) {
		bool done = false;

		for (int j = l, cn = 0; j < r; j++, cn++) {
			if (j == r - 1) done = t[j] == s[i+cn];
			if (t[j] != s[i+cn]) break;
		}

		if (done) return {i, i + r - l};
	}

	return {-1, -1};
}

bool solve(string& t) {
	for (int i = 1; i < t.size(); i++) {
		pii beg = check(0, t, 0, i);
		if (beg == make_pair(-1, -1)) continue;

		pii end = check(beg.second, t, i, t.size());
		if (end == make_pair(-1, -1)) continue;

		return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> s;

	int n, ans = 0; cin >> n;
	while(n--) {
		string t; cin >> t;
		ans += solve(t);
	}

	cout << ans << endl;
}