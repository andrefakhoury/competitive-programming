#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, v; scanf("%d%d", &n, &v);

	int qtt = min(n - 1, v);
	int ans = qtt;

	for (int i = 2; i <= n; i++) {
		qtt--;

		if (qtt < n-i) {
			int buy = min(n-i - qtt, v - qtt);
			ans += buy * i;
			qtt += buy;
		}
	}

	printf("%d\n", ans);

	return 0;
}