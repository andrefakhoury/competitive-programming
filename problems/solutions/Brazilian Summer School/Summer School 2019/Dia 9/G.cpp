#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int ans = 0;

	while (a >= 1 && b >= 2 && c >= 4) {
		a -= 1;
		b -= 2;
		c -= 4;
		ans += 7;
	}

	cout << ans << endl;
}