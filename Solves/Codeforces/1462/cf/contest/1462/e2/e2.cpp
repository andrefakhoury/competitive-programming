#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

const ll MOD = 1e9 + 7;

ll mul(ll x, ll y) {
	return x * y % MOD;
}

ll inv(ll x) {
	ll r = 1;
	for (ll y = MOD-2; y; y /= 2) {
		if (y%2) r = mul(r, x);
		x = mul(x, x);
	}
	return r;
}

ll fac[MAXN];

ll nck(ll n, ll k) {
	if (k > n) return 0;
	return mul(fac[n], inv(mul(fac[k], fac[n-k])));
}

inline void _solve_(int __ntest__) {
	int n, m, k; rd(n, m, k);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		int j = lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();
		ans += nck(i - j, m - 1);
		ans %= MOD;
	}

	printf("%lld\n", ans);
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++) fac[i] = mul(fac[i-1], i);

	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}