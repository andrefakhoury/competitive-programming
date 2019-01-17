#include <bits/stdc++.h>

using namespace std;

int main() {
	string text, res;
	char t1;
	cin >> text;

	for (int i = 0; i < text.size(); i++) {
		text[i] = tolower(text[i]);
	}

	for (int i = 0; i < text.size(); i++) {
		t1 = text[i];
		if (t1 == "a" || t1 == "e" || t1 == "i" || t1 == "o" || t1 == "u" || t1 == "y")
			continue;
		res.push_back("."); res.push_back(t1);
	}

	cout << res << endl;

	return 0;
}