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

const int N = 50 + 5, INF = 0x3f3f3f3f;
const int MOD = 998244353;

template <typename T> T add(T x, T y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

template <typename T> T sub(T x, T y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

template <typename T> T mul(T x, T y) { return 1ll * x * y % MOD; }

template <typename T> T inv(T a) {
	T b = MOD-2, r;
	for (r = 1; b; b /= 2, a = mul(a, a))
		if (b % 2 == 1) r = mul(r, a);
	return r;
}

template <typename T> T divi(T x, T y) { return mul(x, inv(y)); }

int good[N];
int val[N];

map<tuple<int, int, int, int>, int> memo;

using tp=tuple<int, int, int, int>;

int solve(int m, int cur, int sgood, int sbad, int delta) {
	if (m == 0) return cur;
	tp stt = {m, cur, sgood, delta};
	if (memo.count(stt)) return memo[stt];

	int sum = add(add(sgood, sbad), cur);

	int p1 = divi(cur, sum);
	int p2 = divi(sub(sum, cur), sum);

	int pgood = divi(sgood, add(sgood, sbad));
	int pbad = divi(sbad, add(sgood, sbad));

	int ret = 0;
	if (cur + delta >= 0)
		ret = add(ret, mul(p1, solve(m-1, cur + delta, sgood, sbad, delta)));
	ret = add(ret, mul(p2, (mul(pgood, solve(m-1, cur, sgood + 1, sbad, delta)))));
	if (sbad >= 1)
		ret = add(ret, mul(p2, mul(pbad, solve(m-1, cur, sgood, sbad - 1, delta))));
	return memo[stt] = ret;
}

int main() {
	int n, m; rd(n, m);
	for (int i = 1; i <= n; i++) rd(good[i]);
	for (int i = 1; i <= n; i++) rd(val[i]);

	int sum = 0;
	for (int i = 1; i <= n; i++) sum = add(sum, val[i]);

	int sgood = 0, sbad = 0;
	for (int i = 1; i <= n; i++) {
		if (good[i]) sgood = add(sgood, val[i]);
		else sbad = add(sbad, val[i]);
	}

	for (int i = 1; i <= n; i++) {
		int cgood = sgood, cbad = sbad;
		if (good[i]) cgood = sub(cgood, val[i]);
		else cbad = sub(cbad, val[i]);
		printf("%d\n", solve(m, val[i], cgood, cbad, 2 * good[i] - 1));
	}
}