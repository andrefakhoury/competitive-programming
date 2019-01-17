#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	for (int a = 0; a < n; a++) {
		cin >> str;
		if (str.size() <=10) {
			cout << str << "\n";
		} else {
			printf("%c%d%c\n", str[0], (int)str.size()-2, str[str.size()-1]);
		}
	}
	return 0;
}
