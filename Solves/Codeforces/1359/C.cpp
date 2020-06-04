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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

ll h, c, t;

inline double f(ll x) {
	if (x == 0) return 1e12;
	return abs(t - double(x * h + x * c - c) / (2 * x - 1));
}

inline ll getx() {
	ll lo = 1, hi = 1e10, mi;
	while(lo < hi) {
		ll mi = (lo + hi) / 2;

		if (f(mi) <= f(mi+1)) hi = mi;
		else lo = mi + 1;
	}

	return lo;
}

inline void _solve_(int __ntest__) {
	rd(h, c, t);

	ll x = getx();

	double f1 = f(x);
	double f2 = abs(t - (h + c) / 2.0);

	if (f1 < f2) {
		printf("%lld\n", x + x - 1);
	} else {
		printf("2\n");
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}