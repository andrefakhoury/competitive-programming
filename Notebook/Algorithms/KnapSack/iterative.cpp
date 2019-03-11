#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3, INF = 0x3f3f3f3f;

int r[MAXN], w[MAXN];

int zeroOne_it(int n, int s) {
	vector<int> memo(s+1);
	fill(memo.begin(), memo.end(), -INF);

	int ans = 0;

	memo[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = s-w[i]; j >= 0; j--) {
			memo[j + w[i]] = max(memo[j + w[i]], memo[j] + r[i]);
			ans = max(ans, memo[j + w[i]]);
		}
	}
	return ans;
}

int zeroOne_rc(int i, int cur, int n, int s) {
	if (cur > s) return -INF;
	if (i > n) return 0;

	return max(zeroOne_rc(i+1, cur, n, s), zeroOne_rc(i+1, cur+w[i], n, s) + r[i]);
}

int zeroInf_it(int n, int s) {
	vector<int> memo(s+1);
	fill(memo.begin(), memo.end(), -INF);

	int ans = 0;

	memo[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s - w[i]; j++) {
			memo[j + w[i]] = max(memo[j + w[i]], memo[j] + r[i]);
			ans = max(ans, memo[j + w[i]]);
		}
	}
	return ans;
}

int zeroInf_rc(int i, int cur, int n, int s) {
	if (cur > s) return -INF;
	if (i > n) return 0;

	int take = zeroInf_rc(i, cur+w[i], n, s) + r[i];
	int notk = zeroInf_rc(i+1, cur, n, s);

	return max(take, notk);
}

int main() {
	int n, s; scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d%d", r+i, w+i);
	printf("%d\n", zeroOne_it(n, s));
	printf("%d\n", zeroOne_rc(1, 0, n, s));

	printf("%d\n", zeroInf_it(n, s));
	printf("%d\n", zeroInf_rc(1, 0, n, s));
}
