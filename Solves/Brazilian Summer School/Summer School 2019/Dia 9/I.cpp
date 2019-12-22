#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	long long ans = 0, cur = 0;

	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if (x != cur) ans += abs(cur - x);
		cur = x;
	}

	printf("%lld\n", ans);
}