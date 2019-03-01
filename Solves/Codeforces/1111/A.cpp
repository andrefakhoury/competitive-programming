#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

bool isCons(char c) {
	return !isVowel(c);
}

void impossible() {
	cout << "No\n";
	exit(0);
}

int main() {
	string s, t; cin >> s >> t;
	if (s.size() != t.size()) impossible();

	for (int i = 0; i < (int)s.size(); i++) {
		if (isVowel(s[i]) && isCons(t[i])) impossible();
		if (isCons(s[i]) && isVowel(t[i])) impossible();
	}

	cout << "Yes\n";
	return 0;
}