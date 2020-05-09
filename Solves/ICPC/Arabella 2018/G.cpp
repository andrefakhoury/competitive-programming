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

const int MAXN = 500 + 5, INF = 0x3f3f3f3f;

ll a[MAXN][MAXN];
int n, m; 
ll v[MAXN][MAXN][4];

inline void calc(int I, int J, int si, int sj, int ind) {
	for (int i = I; i <= n && i >= 1; i += si) {
		for (int j = J; j <= m && j >= 1; j += sj) {
			v[i][j][ind] = max({v[i-si][j][ind], v[i][j-sj][ind], a[i][j]});
		}
	}
}

inline void _solve_(int __ntest__) {
	memset(a, 0, sizeof a);
	memset(v, 0, sizeof v);

	rd(n, m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rd(a[i][j]);
		}
	}

	int ii[4] = {1, 1, n, n};
	int ij[4] = {1, m, 1, m};
	int si[4] = {1, 1, -1, -1};
	int sj[4] = {1, -1, 1, -1};
	for (int k = 0; k < 4; k++) {
		calc(ii[k], ij[k], si[k], sj[k], k);
	}

	ll ans = LLONG_MAX;
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			ll mx = LLONG_MIN;
			ll mn = LLONG_MAX;

			for (int k = 0; k < 4; k++) {
				mx = max(mx, v[i-si[k]][j-sj[k]][k]);
				mn = min(mn, v[i-si[k]][j-sj[k]][k]);
			}

			ans = min(ans, mx - mn);
		}
	}

	printf("%lld\n", ans);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}