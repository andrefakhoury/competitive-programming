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
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;

inline void read(ll* v, int n, int k) {
	for (int i = 1; i <= k; i++) rd(v[i]);
	ll a, b, c, d; rd(a, b, c, d);
	for (int i = k + 1; i <= n; i++)
		v[i] = (a * v[i - 2] + b * v[i - 1] + c) % d + 1;
}

ll p[MAXN];
ll q[MAXN];

inline void _solve_(int __ntest__) {
	printf("Case #%d: ", __ntest__);

	int n, m, k, s; rd(n, m, k, s);
	read(p, n, k);
	read(q, m, k);

	sort(p+1, p+n+1);
	sort(q+1, q+m+1);

	auto check = [&](ll t) {
		int j = 1;
		for (int i = 1; i <= m;) {
			j = lower_bound(p+j, p+n+1, q[i] - t) - p;
			if (j > n or abs(p[j] - q[i]) > t) return false;
			ll beg = q[i];
			while(i <= m && (q[i] - beg + min(abs(p[j] - q[i]), abs(p[j] - beg))) <= t) i++;
			j++;
		}
		return true;
	};

	ll lo = 1, hi = 1e10, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (check(mi)) hi = mi;
		else lo = mi + 1;
	}
	printf("%lld\n", hi);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}