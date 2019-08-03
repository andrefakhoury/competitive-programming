#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	reverse(a.begin(), a.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (i < k) {
			if (a[i] < x) ans += a[i];
			else ans += x;
		} else {
			ans += a[i];
		}
	}

	cout << ans << endl;
}