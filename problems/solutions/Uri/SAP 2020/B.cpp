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

const int MAXN = 1e6 + 5;

ll n, m, x, y;
ll a[MAXN];
ll memo[MAXN][3];

inline int fnx(int i, int k) {
	return lower_bound(a, a+n+2, a[i] - k) - a;
}

ll solve(int i, int old) {
	if (i == 0) return 0;

	ll& ret = memo[i][old];
	if (~ret) return ret;

	ret = n+2;
	if (fnx(i, x) != i) ret = min(ret, 1 + solve(fnx(i, x), 0));

	if (!old && fnx(i, y) != i) {
		int x2 = fnx(i, y);
		ret = min(ret, 1 + solve(x2, 1));
		if (x2+1 != i) ret = min(ret, 1 + solve(x2+1, 1));
	}
	
	return ret;
}

int main() {
	rd(n, m);

	a[0] = 1, a[n+1] = m;
	for (int i = 1; i <= n; i++) rd(a[i]);

	rd(x, y);
	mset(memo, -1);
	ll ans = solve(n+1, 0);
	printf("%lld\n", ans <= n+1 ? ans : -1);
}