/** Maximum Sum of Subarray, O(n) */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;

ll a[MAXN];

ll kadane(int n) {
	ll ans = 0, cur = 0;

	for (int i = 1; i <= n; i++) {
		cur = max(cur + a[i], 0LL);
		ans = max(ans, cur);
	}

	return ans;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a+i);
	printf("%lld\n", kadane(n));
}