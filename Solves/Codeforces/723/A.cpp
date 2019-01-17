#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[3];
	for (int i = 0; i < 3; i++) cin >> a[i];

	int ans = INT_MAX;
	for (int i = 0; i <= 100; i++) {
		int dist = 0;
		for (int k = 0; k < 3; k++) dist += abs(a[k] - i);
		ans = min(ans, dist);
	}

	cout << ans << endl;
}
