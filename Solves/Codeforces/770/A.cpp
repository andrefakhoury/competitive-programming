#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	int n, k, c; cin >> n >> k;

	string ans = "";
	c = 0;

	for (int i = 0; i < n; i++) {
		ans.push_back(c + "a");

		c = (c+1)%k;
	}

	cout << ans << endl;
}