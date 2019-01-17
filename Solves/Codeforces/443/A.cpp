#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	set<char> s;

	while(cin >> c) if (c >= "a" && c <= "z") s.insert(c);
	cout << s.size() << endl;
}