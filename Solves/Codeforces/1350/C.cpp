#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

map<ll, int> f;

inline void factor(ll n) {
	for (ll p = 2; p * p <= n; p++) {
		if (n%p == 0) {
			ll cur = p;
			while(n%p == 0) {
				n /= p;
				f[cur]++;
				cur *= p;
			}
		}
	}
	if (n > 1) f[n]++;
}

int main() {
	int n; rd(n);

	for (int i = 1; i <= n; i++) {
		int x; rd(x);
		factor(x);
	}

	ll ans = 1;
	for (auto p : f) {
		if (p.se >= n-1) {
			ans = lcm(ans, p.fi);
		}
	}

	printf("%lld\n", ans);

}