#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

ll a[MAXN], sum[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	while(t--) {
		memset(sum, 0, sizeof sum);

		int n, k; cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}

		ll ans = 0, qtd = 0;
		for (int i = 1; i <= n; i++) {
			int cur = upper_bound(sum+i, sum+n+1, k+sum[i-1]) - sum - 1;

			if ((cur - i + 1 == qtd && sum[cur] - sum[i-1] < ans) || (cur - i + 1 > qtd)) {
				qtd = cur - i + 1;
				ans = sum[cur] - sum[i-1];
			}
		}

		cout << ans << ' ' << qtd << '\n';
	}

	return 0;
}