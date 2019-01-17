#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	
	int count = 0;
	for (int i = 0; i < s.size(); i++)
		count += s[i] == "4" || s[i] == "7";
	if (count == 4 || count == 7) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}