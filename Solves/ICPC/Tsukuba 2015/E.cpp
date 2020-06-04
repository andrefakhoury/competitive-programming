#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

ll dp_sum[15][300];

ll solve_sum(int n, int s) {
	if (n == 0) return s == 0;
	ll& ret = dp_sum[n][s];
	if (~ret) return ret;
	
	ret = 0;
	for (int d = 0; d <= min(9, s); d++)
		ret += solve_sum(n-1, s-d);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	mset(dp_sum, -1);

	ll ans = 0;
	for (int ss = 0; ss <= 140; ss++) {
		for (int dd = 1; dd <= 14; dd++) {
			ans = max(ans, solve_sum(dd, ss));
		}
	}

	printf("%lld\n", ans);

	// string s; cin >> s;
	// int n = s.size();

	// ll ac_sum = 0;
	// ll ac_prod = 1;

	// for (char c : s) {
	// 	ac_sum += c - '0';
	// 	ac_prod *= c - '0' + 1;
	// }

	// ll ans = 0;

	// mset(dp_sum, -1);
	// for (int ss = 0; ss <= 140; ss++) {

	// }

	// mset(dp_sum, -1);
	// for (int x = 0; x < ac_sum; x++)
	// 	ans += solve_sum(n, x);

	// printf("%lld\n", ans);


}