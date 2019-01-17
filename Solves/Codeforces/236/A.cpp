#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, int> m;
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) m[s[i]] = 1;
	for (char i = "a"; i <= "z"; i++) ans += m[i];

	if (ans%2) cout << "IGNORE HIM!\n";
	else cout << "CHAT WITH HER!\n";

	return 0;
}