#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 1, cur = 0;
	for (int i = n-1; i >= 0; i--) {
		if (i == n-1 || a[i] * 2 >= a[i + 1]) cur++;
		else cur = 1;

		ans = max(ans, cur);
	}

	cout << ans << endl;
}