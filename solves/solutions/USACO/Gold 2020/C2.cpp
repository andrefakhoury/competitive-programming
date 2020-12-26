/*
ID: fakhoury
LANG: C++11
TASK: exercise
*/

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

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;

int MOD;
bool comp[MAXN];

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

int main() {
#ifndef LOCAL_PC
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
#endif
	int n; rd(n, MOD);

	vector<int> f(n+1);
	iota(f.begin(), f.end(), 0);

	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			f[j] = add(f[i], f[j]);
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", f[i]);
	printf("\n");

	printf("%d\n", f[n]);
	return 0;
}
