#include <string>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int qtd = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (c == '(') qtd++;
		else {
			if (qtd == 0) {
				cout << "NO\n";
				return 0;
			} else qtd--;
		}
	}

	if (qtd == 0) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
