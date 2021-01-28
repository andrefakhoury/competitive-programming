#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<int> a(n), b(n), sum(2 * n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int ans = 0, delta = 0;
	for (int i = 0; i < n; i++) {
		delta += sum[i];
		int cur_a = (a[i] + delta + 10) % 10;
		int cnt = (b[i] - cur_a + 10) % 10;
		if (10 - cnt < cnt) cnt = cnt - 10;
		cnt = min(cnt, 10 - cnt);
		delta += cnt;
		sum[i + k] -= cnt;
		ans += abs(cnt);
		if (cnt && i + k > n) {
			cout << -1 << "\n";
			return 0;
		}
	}

	cout << ans << "\n";
}