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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

map<pii, ll> memo;

int n;
vector<pii> v;

ll solve(int i, ll cur) {
	if (abs(cur) == 1) return 0;
	if (i == n) return 1e18;

	pii t{i, cur};
	if (memo.count(t)) return memo[t];

	ll ans = solve(i+1, cur);

	ans = min(ans, v[i].se + solve(i+1, gcd(cur, v[i].fi)));

	return memo[t] = ans;
}

int main() {
	rd(n);
	v.resize(n);
	for (int i = 0; i < n; i++) rd(v[i].fi);
	for (int i = 0; i < n; i++) rd(v[i].se);
	ll ans = solve(0, 0);
	printf("%lld\n", ans == 1e18 ? -1 : ans);
}
