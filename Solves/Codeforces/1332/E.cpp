// teste pra ver se da TLE ou WA

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

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

inline int fast_pow(int x, int y) {
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

int n, m;
int L, R;

map<pii, int> memo;

int qtt1;
int qtt2;
int P, I;

int solve(int i, int j) {
	if (i > n || j > m) return 0;
	if (i == n && j == m) return 1;
	if (memo.count({i, j})) return memo[{i, j}];
	return memo[{i, j}] = solve(i+1, j) + solve(i, j+1) - solve(i+1, j+1);
}

int main() {
	rd(n, m, L, R);
	L %= MOD;
	R %= MOD;
	printf("%d\n", fast_pow(divi(mul(n, m), 2), R - L + 1));
}