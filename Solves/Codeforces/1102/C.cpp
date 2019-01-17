#include <bits/stdc++.h>
using namespace std;

int main() {
int n, x, y; scanf("%d%d%d", &n, &x, &y);
	vector<int> d(n);
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);
	sort(d.begin(), d.end());

	if (x > y) return !printf("%d\n", n);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (i%2 == 0) && (d[i] <= x);

	printf("%d\n", ans);
	return 0;
}