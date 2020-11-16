#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset((a), (b), sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}
inline int mul(ll x, ll y) {
	return x * y % MOD;
}

vector<int> edges[MAXN];
int memo[MAXN][2];

int dfs(int u, int k) {
	if (~memo[u][k]) return memo[u][k];
	int n = edges[u].size();
	if (n == 0) return 1;

	vector<int> pr(n+1, 1), sf(n+1, 1);

	for (int i = 0; i < n; i++) pr[i] = sf[i] = dfs(edges[u][i], 0);
	for (int i = 1; i < n; i++) pr[i] = mul(pr[i], pr[i-1]);
	for (int i = n-2; i >= 0; i--)  sf[i] = mul(sf[i], sf[i+1]);
	int s1 = pr[n-1], s2 = 0;

	for (int i = 0; i < n; i++) {
		int x = mul(i ? pr[i-1] : 1, sf[i+1]);
		s2 = add(s2, mul(x, dfs(edges[u][i], 1)));
	}

	if (k == 0) s2 = add(s1, s2);
	return memo[u][k] = s2;
}

int main() {
	int n; rd(n);
	for (int i = 2; i <= n; i++) {
		int p; rd(p);
		edges[p].pb(i);
	}

	mset(memo, -1);
	printf("%d\n", dfs(1, 0));
}