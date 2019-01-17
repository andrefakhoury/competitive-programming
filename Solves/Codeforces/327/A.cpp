#include <bits/stdc++.h>
using namespace std;

int a[200], n;

int solve(int l, int r) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= l && i <= r) ret += !a[i];
		else ret += a[i];
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) { 
			ans = max(ans, solve(i, j));
		}
	}

	cout << ans << endl;
}
