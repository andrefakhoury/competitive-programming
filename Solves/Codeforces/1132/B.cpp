#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a+i);

	long long sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];

	sort(a, a+n);

	int q; scanf("%d", &q);
	while (q--) {
		int x; scanf("%d", &x);
		printf("%lld\n", sum - a[n-x]);
	}

}