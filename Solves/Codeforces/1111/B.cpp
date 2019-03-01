#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
long long sum[MAXN];

double getSum(int l, int r) {
	return sum[r] - sum[l-1];
}

int main() {
	int n, k, m; cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];

	double ans = getSum(1, n) / n;
	for (int i = 1; i <= n; i++) {
		int K = min((n-i) * k, m - i);

		double cur = (getSum(i+1, n) + K) / (n - i);
		ans = max(ans, cur);
	}

	cout << fixed << setprecision(9) << ans << endl;

	return 0;
}