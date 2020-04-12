#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int n;

struct Sqr {
	ll x1, y1, x2, y2;
	Sqr() {}
	inline void read() {
		rd(x1, y2, x2, y2);
	}
} a[MAXN];

inline ll area(ll y) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].y1 >= y) continue;
		ll yy = min(a[i].y2, y);
		ll cur = (a[i].x2 - a[i].x1) * (yy - a[i].y1);
		ans += cur;
	}
	return ans;
}

int main() {
	int k; rd(n, k);

	for (int i = 1; i <= n; i++) a[i].read();

	ll lo = -1e9, hi = 2e9, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (area(mi) >= k) hi = mi;
		else lo = mi + 1;
	}

	if (area(hi) < k) printf("PERDAO MEU REI\n");
	else printf("%lld\n", hi);
}