#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 5e5 + 5, INF = 0x3f3f3f3f;
const int MOD = 998244353;

inline int fpow(int x, int y) {
	if (x == 0) return 0;

	int r = 1;
	for (; y > 0; y /= 2) {
		if (y % 2) r = 1ll * r * x % MOD;
		x = 1ll * x * x % MOD;
	}
	return r;
}

inline int mul(int x, int y) {
	return 1ll * x * y % MOD;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

int f[MAXN];

inline int inv(int n) {
	return fpow(n, MOD-2);
}

inline int nck(int n, int k) {
	if (n < k) return 0;
	return mul(mul(f[n], inv(f[k])), inv(f[n - k]));
}

int main() {
	int n, k; rd(n, k);
	f[0] = 1;
	for (int i = 1; i < MAXN; i++) f[i] = mul(f[i-1], i);

	int ans = 0;
	for (int ini = 1; ini <= n; ini++) {
		int cur = n / ini;
		// tenho cur-1 caras, preciso pegar k-1
		ans = add(ans, nck(cur-1, k-1));
	}

	printf("%d\n", ans);
}
