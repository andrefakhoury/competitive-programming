#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

pii a[MAXN];

int main() {
	#ifndef LOCAL_PC
	freopen("icecream.in", "r", stdin);
	#endif

	int T; rd(T);
	while(T--) {
		int n, k; rd(n, k);
		for (int i = 1; i <= n; i++) rd(a[i].fi);
		for (int i = 1; i <= n; i++) rd(a[i].se);

		sort(a+1, a+n+1);

		int ansfi = a[k].fi;

		int x = k;
		while(x <= n && a[x].fi == a[k].fi) x++;

		sort(a+1, a+x, [&](pii const& X, pii const& Y) {
			return X.se > Y.se;
		});

		ll ans = 0;
		for (int i = 1; i <= k; i++) ans += a[i].se;

		printf("%d %lld\n", ansfi, ans);
	}
}