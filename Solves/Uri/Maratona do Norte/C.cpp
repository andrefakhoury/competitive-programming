#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, c, n; scanf("%d%d%d", &p, &c, &n);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (x - p < 0) break;

		x -= p;
		if (c > x) {
			ans += i != 1;
			c = x;
		}
	}

	printf("%d\n", ans);
}