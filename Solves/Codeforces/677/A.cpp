#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
	int n, h; cin >> n >> h;
	vector<int> a(n+1);
	int ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] <= h) ans++;
		else ans += 2;
	}
	cout << ans << endl;
}