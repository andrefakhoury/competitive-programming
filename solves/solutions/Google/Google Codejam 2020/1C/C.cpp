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
const double EPS = 1e-9;

inline bool eq(double a, double b) {
	return abs(a - b) <= EPS;
}

void print(__int128 x) {
	string ans;
	while(x) {
		ans += (x % 10) + '0';
		x /= 10;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

inline void _solve_(int __ntest__) {
	printf("Case #%d: ", __ntest__);

	int n, d; rd(n, d);
	vector<__int128> a(n);
	for (auto& i : a) rd(i);

	sort(a.begin(), a.end());

	map<pair<ll, double>, bool> isdiv;

	vector<double> all;
	for (int i = 0; i < n; i++) {
		a[i] *= __int128(14) * 15 * 16 * 17 * 18 * 19 * 20 * 21 * 22 * 23 * 24 * 25 * 26;

		// for (int j = 1; j <= 13;)

		// for (int j = 1; j <= 200; j++) {
		// 	double nvo = double(a[i]) / j;
		// 	if (nvo <= EPS) continue;
		// 	all.eb(nvo);
		// 	isdiv[{a[i], all.back()}] = true;
		// }
	}

	// sort(all.begin(), all.end());
	// all.erase(unique(all.begin(), all.end()), all.end());

	// auto isd = [&](ll x, double y) {
	// 	auto it = isdiv.lower_bound({x, y - EPS});
	// 	if (it == isdiv.end()) return false;
	// 	return eq(y, it->fi.se);
	// };

	// ll ans = INT_MAX;
	// for (auto x : all) {
	// 	ll cur = 0;
	// 	vector<pii> alldiv;
	// 	ll cntAll = 0;

	// 	for (int i = 0; i < n; i++) {
	// 		if (a[i]+EPS < x) continue;
	// 		ll N = a[i] / x;
	// 		if (isd(a[i], x)) alldiv.eb(N-1, N);
	// 		else cntAll += N;
	// 	}

	// 	sort(alldiv.begin(), alldiv.end());

	// 	ll D = d;
	// 	for (auto p : alldiv) {
	// 		if (D >= p.se) {
	// 			D -= p.se;
	// 			cur += p.fi;
	// 		}
	// 	}

	// 	if (cntAll >= D) {
	// 		ans = min(ans, cur + D);
	// 	}
	// }

	// printf("%lld\n", ans);
	print(a[0]);
	printf("\n");
}

int main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}