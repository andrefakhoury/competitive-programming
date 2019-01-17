#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int j = 0;
	string h = "helloAIOJSDASDIJ";
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == h[j]) j++;
	cout << (j >= 5 ? "YES" : "NO") << endl;
	return 0;
}