#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<string, int> reg;
	int n; cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		reg[s]++;
		if (reg[s] == 1) cout << "OK\n";
		else cout << s << reg[s]-1 << endl;
	}
}
