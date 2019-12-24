#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, p, k;
vector<ll> a, sum[MAXN];
ll qtt[MAXN], acc[MAXN];

inline void _solve() {
	memset(acc, 0, sizeof acc);
	memset(qtt, 0, sizeof qtt);

	cin >> n >> p >> k;
	a.resize(n);
	for (ll& i : a) cin >> i;
	sort(a.begin(), a.end());

	for (int i = 0; i < k; i++) sum[i].eb(0);
	for (int i = 0; i < n; i++) sum[i%k].eb(sum[i%k].back() + a[i]);

	int ans = 0;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur > p) break;
		ans = max(ans, i);

		ll at = p - cur;
		int blk = (i+k-1)%k;

		auto it = upper_bound(sum[blk].begin() + qtt[blk], sum[blk].end(), at+acc[blk]);
		it--;

		if (it != sum[blk].end() && *it <= at+acc[blk]) {
			int ind = it - (sum[blk].begin() + qtt[blk]);
			ans = max(ans, i + k * ind);
		}

		cur += a[i];
		qtt[i%k]++;
		acc[i%k] += a[i];
	}

	cout << ans << '\n';

	for (int i = 0; i < k; i++) sum[i].clear();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}