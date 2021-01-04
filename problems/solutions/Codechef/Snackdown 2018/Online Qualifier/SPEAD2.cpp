#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
typedef long long ll;

ll a[MAXN], sum[MAXN];

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", a+i);
		for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];

		ll j = 1, ans = 0;
		while (j < n) {
			j += sum[j];
			ans++;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}