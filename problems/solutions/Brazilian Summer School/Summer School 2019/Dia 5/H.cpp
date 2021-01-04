#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cout << "::" << (#x) << ": " << (x) << endl
const int MAXN = 200005;
int n, a[MAXN];

double sum(double x) {
	double ans = -1000000000;

	double cur = 0, mi = a[1] - x, ma = a[1] - x;
	for (int i = 1; i <= n; i++) {
		cur += a[i] - x;

		ans = max(ans, abs(cur));
		ans = max(ans, abs(cur - mi));
		ans = max(ans, abs(cur - ma));

		mi = min(mi, cur);
		ma = max(ma, cur);
	}

	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	double lo, hi, mi1, mi2;
	int cnt = 500;

	hi = 10000000000;
	lo = -1000000000;
	while(cnt--) {
		mi1 = (2 * lo + hi) / 3;
		mi2 = (lo + 2 * hi) / 3;

		if (sum(mi1) > sum(mi2)) {
			lo = mi1;
		} else {
			hi = mi2;
		}
	}

	printf("%.10lf\n", sum(lo));
}