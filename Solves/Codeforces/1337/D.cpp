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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5;
inline void _solve_(int __ntest__) {
	int n[3]; rd(n[0], n[1], n[2]);
	vector<ll> a[3];
	for (int i = 0; i < 3; i++) {
		a[i].resize(n[i]);
		for (ll& j : a[i]) rd(j);
		sort(a[i].begin(), a[i].end());
		a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
	}

	auto f = [](ll a, ll b, ll c) {
		return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
	};

	auto solve = [&f](vector<ll>& x, vector<ll>& y, vector<ll>& z) {
		ll ret = LLONG_MAX;
		for (ll& i : x) {
			auto i1 = upper_bound(y.begin(), y.end(), i);
			if (i1 == y.begin()) continue;
			i1--;
			auto i2 = lower_bound(z.begin(), z.end(), i);
			if (i2 == z.end()) continue;
			ret = min(ret, f(i, *i1, *i2));
		}
		return ret;
	};

	ll ans = LLONG_MAX;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == k or i == j or j == k) continue;
				ans = min(ans, solve(a[i], a[j], a[k]));
			}
		}
	}

	printf("%lld\n", ans);


}

int main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}