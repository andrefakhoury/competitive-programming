#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();

	string tmp = "";
	for (int i = 0; i < n; i++) {
		if (i <= n-3 && s[i] == "W" && s[i+1] == "U" && s[i+2] == "B") {
			if (tmp != "") {
				cout << tmp << " ";
			}
			tmp.clear();
			i += 2;
		} else tmp.push_back(s[i]);
	}
	cout << tmp << endl;
	return 0;
}