#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

	int ans = 2, wh = 0, br = -1;
	for (int i = s.size()-1; i >= 0; i--)  {
		if (wh == 0 && s[i] == ']') wh++;
		if (wh == 1 && s[i] == ':') {
			br = i;
			break;
		}
	}

	wh = 0;
	for (int i = 0; i < br; i++) {
		if (wh == 0 && s[i] == '[') {
			wh++; ans++;
		} else if (wh == 1 && s[i] == ':') {
			wh++; ans++;
		} else if (wh == 2 && s[i] == '|') {
			ans++;
		}
	}

	cout << ((ans < 4) ? -1 : ans) << endl;
}