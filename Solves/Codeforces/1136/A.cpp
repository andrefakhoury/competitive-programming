#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i].first >> c[i].second;
	int k; cin >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += k <= c[i].second;
	}

	cout << ans << endl;
}