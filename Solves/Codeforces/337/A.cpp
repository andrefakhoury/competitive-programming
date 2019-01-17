#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int ans = INT_MAX;
	for (int i = 0; i <= m-n; i++) {
		int cur = 0;
		for (int j = i+1; j < i+n; j++)
			cur = max(cur, a[j]-a[i]);
		ans = min(ans, cur);
	}

	cout << ans << endl;
}