#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

char s[MAXN];
inline void _solve_(int __ntest__) {
	int n; cin >> n;
	vector<int> price(1024);
	for (int i = 0; i < n; i++) {
		unsigned char c;
		int p;
		cin >> c >> p;
		price[c] = p;
	}

	int k; cin >> k;

	long long ans = 0;
	string s;
	cin.ignore();
	for (int i = 0; i < k; i++) {
		getline(cin, s);
		for (int j = 0; j < (int) s.size(); j++) 
			ans += price[s[j]];
	}

	cout << ans/100 << '.';
	if (ans%100 < 10) cout << 0;
	cout << ans%100 << "$";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) {
		_solve_(__i__);
                cout << "\n";
	}

	return 0;
}