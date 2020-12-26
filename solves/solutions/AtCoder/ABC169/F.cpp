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

const int MAXN = 3e3 + 5, INF = 0x3f3f3f3f;
const int MOD = 998244353;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int inv(int x) {
	int y = MOD-2;
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

int n, k;
int a[MAXN];
int memo[MAXN][MAXN];
int pot;
int iv2;

int solve(int i, int sum) {
	if (sum < 0) return 0;
	if (i > n) return (!sum) * pot;
	int& ret = memo[i][sum];
	if (~ret) return ret;

	ret = solve(i+1, sum);
	ret = add(ret, mul(iv2, solve(i+1, sum - a[i])));
	return ret;
}


int main() {
	iv2 = inv(2);
	pot = 1;

	rd(n, k);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		pot = mul(pot, 2);
	}

	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(1, k));
}