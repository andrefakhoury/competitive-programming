#include <bits/stdc++.h>
using namespace std;

int toint(char c) {
	if (c >= "A" && c <= "Z") return c-"A";
	if (c >= "a" && c <= "z") return c-"a";
	return 27;
}

int aoba[30];
int main() {
	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) aoba[toint(s[i])] = 1;
	for (int i = 0; i < 26; i++) if (!aoba[i]) return !printf("NO\n");
	return !printf("YES\n");
}