#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		string s; cin >> s;
		string a, bb;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '4') {
				a += s[i];
				bb += '0';
			} else {
				a += '3';
				bb += '1';
			}
		}

		string b;
		for (int i = 0, hs = 0; i < bb.size(); i++) {
			if (bb[i] != '0') hs = 1;
			if (hs) b += bb[i];
		}

		cout << "Case #" << cs << ": " << a << " " << b << "\n";
	}
}