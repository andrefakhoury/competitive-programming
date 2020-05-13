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
inline void _solve_(int __ntest__) {
	int n; rd(n);
	vector<int> a(n);
	for (auto& i : a) rd(i);

	pii mxPos{-1, -1};
	pii mnNeg{-1, -1};

	vector<ll> ans(n);

	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			ans[i] = (mnNeg.se != -1 ? ans[mnNeg.se] : 0) + a[i];
			if (mxPos.se <= mnNeg.se or mxPos.fi < a[i]) {
				mxPos = {a[i], i};
			}
		} else { // pego o maior positivo
			ans[i] = (mxPos.se != -1 ? ans[mxPos.se] : 0) + a[i];
			if (mnNeg.se <= mxPos.se or mnNeg.fi < a[i]) {
				mnNeg = {a[i], i};
			}
		}
	}

	ll res = LLONG_MIN;
	for (int i = n-1; i >= 0 && a[i] < 0; i--) res = max(res, ans[i]);
	for (int i = n-1; i >= 0 && a[i] > 0; i--) res = max(res, ans[i]);

	printf("%lld\n", res);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}	