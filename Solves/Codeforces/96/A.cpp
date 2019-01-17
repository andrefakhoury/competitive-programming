#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define debugg(a) cout << ">>" << (#a) << " : " << (a) << endl;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int qt0 = 0, qt1 = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == "0") {
			qt0++; qt1 = 0;
		} else if (s[i] == "1") {
			qt1++; qt0 = 0;
		}

		if (qt0 == 7 || qt1 == 7) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}