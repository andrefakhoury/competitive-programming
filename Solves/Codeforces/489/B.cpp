#include <bits/stdc++.h>
using namespace std;

int grill[500];
int main() {
	int n, m; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	cin >> m;
	vector<int> g(m);
	for (int i = 0; i < m; i++) {
		cin >> g[i];
		grill[g[i]]++;
	}

	sort(b.begin(), b.end());

	int ans = 0;
	for (int i = 0; i < b.size(); i++) {
		ans++;
		if (grill[b[i]-1]) grill[b[i]-1]--;
		else if (grill[b[i]]) grill[b[i]]--;
		else if (grill[b[i]+1]) grill[b[i]+1]--;
		else ans--;
	}

	cout << ans << endl;
}