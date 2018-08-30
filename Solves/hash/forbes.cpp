#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	
	string str; cin >> str; str = " " + str;
	set<string> s;

	for (int k = n; k >= 1; k--) {
		for (int i = 1; i <= n-(k+1); i++) {
			if (s.count(str.substr(i, k))) //achou
			s.insert(str.substr(i, k));
		}
		s.clear();
	}

}