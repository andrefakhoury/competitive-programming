#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> p(n);
	cin >> p[0];

	int maxi, mini;
	maxi = mini = p[0];

	int ans = 0;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		if (p[i] > maxi || p[i] < mini) ans++;
		maxi = max(p[i], maxi);
		mini = min(p[i], mini);
	}

	cout << ans << endl;
}
