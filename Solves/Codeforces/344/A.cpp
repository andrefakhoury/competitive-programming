#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	int n; cin >> n;
	string s, t = "";
	for (int i = 0; i < n; i++) {
		cin >> s;
		t += s;
	}

	int ans = 1;
	for (int i = 1; i < t.size(); i++) {
		if (t[i] == t[i-1]) ans++;
	}

	cout << ans << endl;
}