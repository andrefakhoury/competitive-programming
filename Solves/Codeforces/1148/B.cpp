#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN], n, m, ta, tb, k;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);

	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= m; i++) scanf("%d", b+i);

	long long ans = 0;
	for (int ka = 0, kb = k; ka <= k; ka++, kb--) {
		if (ka >= n) return !printf("-1\n");

		long long t_inB = a[1+ka] + ta;
		int ib = lower_bound(b+1, b+1+m, t_inB) - (b);

		if (ib + kb > m) return !printf("-1\n");
		long long t_inC = b[ib + kb] + tb;

		ans = max(ans, t_inC);
	}

	printf("%lld\n", ans);
}