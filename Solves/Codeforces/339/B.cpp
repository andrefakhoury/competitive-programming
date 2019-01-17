#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int cur = 0, x;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x); x--;
		ans += (x-cur+n)%n;
		cur = x;
	}
	printf("%lld\n", ans);
	return 0;
}