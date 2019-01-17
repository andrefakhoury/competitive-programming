#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p = 0, a, b, ans = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		p -= a; p += b;
		ans = max(ans, p);
	}
	printf("%d\n", ans);
}