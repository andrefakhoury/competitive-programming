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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

const int MAXN = 20 + 5, INF = 0x3f3f3f3f;

pii vec[MAXN][MAXN];
ll fac[MAXN];

ll solve(int current, vector<int> const& masks, vector<ll> const& memo, vector<ll>& dp) {
	ll& ret = dp[current];
	if (~ret) return ret;

	ret = 0;
	for (int m : masks) {
		if (m & current) continue;
		ret = max(ret, memo[m] + solve(current|m, masks, memo, dp));
	}

	return ret;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++) fac[i] = i * fac[i-1];

	int n; scanf("%d", &n);
	vector<pii> a(n);
	for (pii& i : a) scanf("%d%d", &i.fi, &i.se);

	auto normalize = [](pii a) {
		int g = __gcd(a.fi, a.se);
		return pii{a.fi/g, a.se/g};
	};

	vector<pii> all;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
		vec[i][j] = normalize({a[j].fi - a[i].fi, a[j].se - a[i].se});
		all.push_back(vec[i][j]);
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	vector<ll> memo(1 << n);
	vector<int> masks;
	for (auto p : all) {
		bitset<16> used = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j && !used[i] && !used[j]) {
			if (vec[i][j] == p) {
				cnt++;
				used[i] = used[j] = 1;
			}
		}

		int curMask = used.to_ulong();
		memo[curMask] = max(memo[curMask], cnt);
		masks.pb(curMask);
	}

	vector<long long> dp(1 << n, -1);
	printf("%lld\n", solve(0, masks, memo, dp));
}