#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

bool isVogal(char c) {
	return c == "a" || c == "e" || c == "i" || c == "o" || c == "u";
}

bool isImpar(char c) {
	return (c-"0" >= 0 && c-"0" <= 9 && (c-"0")%2 != 0);
}

int main() {
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans += isVogal(s[i]) || isImpar(s[i]);
	}
	cout << ans << endl;
	return 0;
}