#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;

	set<int> pos[3];

	for (int i = 0; i < n; i++) pos[s[i]-"0"].insert(i);
	int k = n/3;

	while(pos[0].size() < k) {
		int m1 = INT_MAX, m2 = INT_MAX;
		if (pos[1].size() > k) m1 = *(pos[1].begin());
		if (pos[2].size() > k) m2 = *(pos[2].begin());

		int p = min(m1, m2);
		int old = s[p]-"0";

		pos[old].erase(p);
		pos[0].insert(p);
		s[p] = "0";
	}
	
	while(pos[2].size() < k) {
		int m0 = -1, m1 = -1;
		if (pos[0].size() > k) m0 = *(pos[0].rbegin());
		if (pos[1].size() > k) m1 = *(pos[1].rbegin());

		int p = max(m0, m1);
		int old = s[p]-"0";

		pos[old].erase(p);
		pos[2].insert(p);
		s[p] = "2";
	}

	while(pos[1].size() < k) {
		if (pos[2].size() > k) {
			int p = *(pos[2].begin());
			
			pos[2].erase(p);
			pos[1].insert(p);
			s[p] = "1";
		} else if (pos[0].size() > k) {
			int p = *(pos[0].rbegin());
			
			pos[0].erase(p);
			pos[1].insert(p);
			s[p] = "1";
		}
	}


	cout << s << endl;


}