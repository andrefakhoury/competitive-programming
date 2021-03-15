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

vector<ll> get(ll a) {
	vector<ll> cur;

	ll pot = 1;
	while(a > 0) {
		if (a%10) {
			cur.eb((a%10) * pot);
		}
		a /= 10;
		pot *= 10;
	}
	return cur;

}

inline void _solve_(int __ntest__) {
	ll a, b; rd(a, b);

	bool neg = (a < 0) ^ (b < 0);
	a = abs(a), b = abs(b);

	vector<ll> x = get(a);
	vector<ll> y = get(b);

	vector<pii> ans;
	for (ll i : x) for (ll j : y) ans.eb(i, j);

	for (int i = 0; i < (int) ans.size(); i++) {
		if (neg) printf("-");
		if (i > 0) printf(" ");
		printf("%d x %d ", ans[i].fi, ans[i].se);
		if (i + 1 < (int) ans.size() && !neg) printf("+ ");
	}
	printf("\n");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}