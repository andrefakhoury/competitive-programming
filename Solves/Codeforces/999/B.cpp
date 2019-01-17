#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s; cin >> s;

	vector<int> dividers;
	for (int i = n; i > 1; i--)
		if (n%i == 0) dividers.push_back(i);

	while(dividers.size()) {
		reverse(s.begin(), s.begin()+dividers.back());
		dividers.pop_back();
	}
	cout << s << endl;
	return 0;
}