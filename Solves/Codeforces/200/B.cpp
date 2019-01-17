#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	double ans = 0, x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		ans += x;
	}

	cout << fixed << setprecision(12) << ans/n << endl;

}