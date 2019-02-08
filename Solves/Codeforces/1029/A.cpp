#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	string t; cin >> t;

	int s = n;
	for (int i = n-1; i > 0; i--)
		if (t.substr(i, n-i) == t.substr(0, n-i)) s = i;

	cout << t;
	k--;
	while (k--) {
		for (int i = n - s; i < n; i++) cout << t[i];
	} cout << endl;
}