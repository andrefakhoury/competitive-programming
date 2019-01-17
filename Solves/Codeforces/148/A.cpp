#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, n, ans = 0; cin >> a >> b >> c >> d >> n;
	for (int i = 1; i <= n; i++)
		if (i%a == 0 || i%b == 0 || i%c == 0 || i%d == 0) ans++;
	cout << ans << endl;
}