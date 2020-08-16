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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
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
	T u = 0, v = 1, m = MOD;
	while (a != 0) {
		T t = m / a;
		m -= t * a; std::swap(a, m);
		u -= t * v; std::swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T> T div(T x, T y) { return mul(x, inv(y)); }

vector<int> edges[MAXN];
int fac[MAXN];

int dfs(int u, int p = -1) {
	int sz = edges[u].size();
	int ret = fac[sz];

	for (int v : edges[u]) if (v != p) {
		ret = mul(ret, dfs(v, u));

	return ret;
}


int main() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fac[i] = mul(i, fac[i-1]);

	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	printf("%d\n", mul(dfs(1), n));
}