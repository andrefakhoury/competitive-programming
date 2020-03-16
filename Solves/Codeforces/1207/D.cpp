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
const int MAXN = 3e5 + 5;
const int MOD = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace modint {
	inline int add(int x, int y) {
		x += y;
		if (x >= MOD) x -= MOD;
		return x;
	}

	inline int sub(int x, int y) {
		x -= y;
		if (x < 0) x += MOD;
		return x;
	}

	inline int mul(int x, int y) {
		return ll(x) * y % MOD;
	}

	inline int inv(int x) {;
		int y = MOD-2;
		int res = 1;
		while (y > 0) {
			if (y & 1) res = mul(res, x);
			x = mul(x, x);
			y >>= 1;
		}
		return res;
	}

	inline int div(int x, int y) {
		return mul(x, inv(y));
	}
};

int fat[MAXN];
pii a[MAXN];

inline void init() {
	fat[0] = 1;
	for (int i = 1; i < MAXN; i++) fat[i] = modint::mul(fat[i-1], i);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	init();

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;

	sort(a+1, a+n+1);
	
	int cnt1 = 1;
	int cnt2 = 1;
	int cnt12 = 1;

	for (int i = 1, cur = 0; i <= n+1; i++)
		if (a[i].fi != a[i-1].fi) cnt1 = modint::mul(cnt1, fat[cur]), cur = 1;
		else cur++;
	for (int i = 1, cur = 0; i <= n+1; i++)
		if (a[i].se && a[i].se < a[i-1].se) cnt12 = 0;
		else if (a[i].fi != a[i-1].fi || a[i].se != a[i-1].se) cnt12 = modint::mul(cnt12, fat[cur]), cur = 1;
		else cur++;
	sort(a+1, a+n+1, [&](pii const& xx, pii const& yy) {
		return xx.se < yy.se;
	});
	for (int i = 1, cur = 0; i <= n+1; i++)
		if (a[i].se != a[i-1].se) cnt2 = modint::mul(cnt2, fat[cur]), cur = 1;
		else cur++;

	int ans = fat[n];
	ans = modint::sub(ans, cnt1);
	ans = modint::sub(ans, cnt2);
	ans = modint::add(ans, cnt12);

	cout << ans << '\n';
	return 0;
}