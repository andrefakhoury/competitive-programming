#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	
	int qt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == "x") qt++;
		else qt = 0;
		
		if (qt == 3) {
			ans++;
			s.erase(s.begin()+i);
			n--;
			i = -1;
			qt = 0;
		}
	}
	cout << ans << endl;
	
	
	
	return 0;
}
