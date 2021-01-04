#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int dist(int x, int y) {
	return x*x + y*y;
}

int main() {
	int r; scanf("%d", &r);

	int x, y;

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &x, &y);
		int d = dist(x, y);

		for (int k = 1; k <= 10; k++) {
			if (d <= r*r*k*k) {
				ans += 10 - k + 1;
				break;
			}
		}
	}


	printf("%d\n", ans);
}