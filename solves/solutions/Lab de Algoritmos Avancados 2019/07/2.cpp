#include <iostream>
#include <string>
using namespace std;

const int n = 131071;

bool validate(string& s) {
	int r = 0;

	for (char c : s) {
		if (c == '#') break;

		if (c == '1') r = (r << 1 | 1) % n;
		else r = (r << 1) % n;
	}
	
	return r%n == 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s;
	while (cin >> s) {
		if (validate(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}