#include <bits/stdc++.h>

using namespace std;

bool vogal(char a, char b) {
	a = tolower(a);
	b = tolower(b);
	if ((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') && ((b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u')))
		return true;
	return false;
}

int main() {
	string inp;
	string ans;
	cin >> inp;

	ans.push_back(inp[0]);
	for (int i = 1; i < inp.size(); i++) {
		if (!vogal(inp[i], inp[i-1]))
			ans.push_back(inp[i]);
	}

	cout << ans << endl;


	return 0;
}