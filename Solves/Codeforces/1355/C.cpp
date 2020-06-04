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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline ll pa(ll a1, ll an) {
	ll ans = an * (an + 1) / 2;
	ans -=   a1 * (a1 + 1) / 2;
	return ans;
}

int main() {
	ll a, b, c, d; rd(a, b, c, d);

	ll ans = 0;
	for (ll x = a; x <= b; x++) {
		ll lo = c, hi = d, mi;
		while(lo < hi) {
			mi = (lo + hi + 1) / 2;
			if (mi - x + 1 <= c) lo = mi;
			else hi = mi - 1;
		}

		ll k1 = max(c - x + 1, b);
		ll k2 = max(lo - x + 1, b);

		k1 = c - k1 + 1;
		k2 = c - k2 + 1;

		ll cur = 0;
		cur += ((lo - c) - (k1 - k2)) * k1;
		cur += pa(k2-1, k1);
		ans += cur;
	}

	printf("%lld\n", ans);
}