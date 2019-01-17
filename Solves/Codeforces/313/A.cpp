#include <bits/stdc++.h>
using namespace std;

int tointe(string& a) {
	if (a.size() == 0) return 0;
	if (a.size() == 1 && a[0] == "-") return 0;
	return stoi(a);
}

int main() {
	string s; cin >> s;

	int ans = stoi(s);
	for (int i = max(0, (int)s.size()-2); i < s.size(); i++) {
		if (s[i] == "-") continue;

		string a = s;
		a.erase(i, 1);
		int cur = tointe(a);
		ans = max(ans, cur);
	}

	cout << ans << endl;
}
