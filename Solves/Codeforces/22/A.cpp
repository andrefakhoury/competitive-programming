#include <bits/stdc++.h>
using namespace std;

int main () {
	set<int> s;
	int n, x; cin >> n;
	while(n--) {
		cin >> x; s.insert(x);
	}
	if ((int)s.size() < 2) return !printf("NO\n");
	auto it = s.begin(); it++;
	cout << *it << endl;
	return 0;
}