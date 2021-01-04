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

const int MAXN = 1e2 + 5, INF = 0x3f3f3f3f;
const int MAXM = 1e4 + 5;

int p;
int a[MAXN];
int b[MAXN];

ll memo[MAXN][MAXM];
bitset<MAXM> vis[MAXN];
int suf[MAXN];

// vai q os casos estao fracos rsrs
ll solve(int i, int n) {
	if (n == 0) return 0;
	if (i > p)  return LLONG_MIN;

	ll& ret = memo[i][n];
	if (vis[i][n]) return ret;
	vis[i][n] = true;

	ret = LLONG_MIN;
	for (int j = a[i]; j <= min(b[i], n - suf[i+1]); j++)
		ret = max(ret, j * j + solve(i+1, n - j));
	return ret;
}

int main() {
	int n; rd(p, n);

	for (int i = 1; i <= p; i++) rd(a[i]);
	for (int i = 1; i <= p; i++) rd(b[i]);
	for (int i = p; i >= 1; i--) suf[i] = suf[i+1] + a[i];

	ll ans = solve(1, n);
	if (ans >= 0) printf("%lld\n", ans);
	else puts("IMPOSSIBLE");
}