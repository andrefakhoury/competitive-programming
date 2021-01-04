#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a[] = {300, 1500, 600, 1000, 150};
	long long ans = 225;

	for (int i = 0; i < 5; i++) {
		int x; scanf("%d", &x);
		ans += x * a[i];
	}

	printf("%lld\n", ans);
}