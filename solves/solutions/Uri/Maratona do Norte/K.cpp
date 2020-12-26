#include <bits/stdc++.h>
using namespace std;

bool check(string& s, int n) {
	int r = 0;

	for (char c : s) {
		if (c == '1') r = (r << 1 | 1) % n;
		else r = (r << 1) % n;
	}
	
	return r%n == 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<int> ans;

	string s; cin >> s;
	int m; cin >> m;
	while(m--) {
		int x; cin >> x;
		if (check(s, x)) ans.push_back(x);
	}

	if (ans.empty()) cout << "Nenhum\n";
	else {
		sort(ans.begin(), ans.end());
		for (int k : ans) cout << k << ' ';
		cout << endl;
	}
}