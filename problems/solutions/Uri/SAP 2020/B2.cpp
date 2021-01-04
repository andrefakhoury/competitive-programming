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

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;

int N;
ll n, m, x, y;
ll a[MAXN];
ll memo[MAXN][3];
int nxt[MAXN][2];

ll seg[4 * MAXN][2];

ll query(int p, int i, int j, int l, int r, int k) {
	if (i > j or i > r or j < l) return INF;
	if (i >= l && j <= r) return seg[p][k];
	int m = (i + j) / 2;
	ll L = query(p+p, i, m, l, r, k);
	ll R = query(p+p+1, m+1, j, l, r, k);
	return min(L, R);
}

void update(int p, int i, int j, int x, int v, int k) {
	if (i == j) seg[p][k] = v;
	else {
		int m = (i + j) / 2;
		if (m >= x) update(p+p, i, m, x, v, k);
		else update(p+p+1, m+1, j, x, v, k);
		seg[p][k] = min(seg[p+p][k], seg[p+p+1][k]);
	}
}

// ll solve(int i, int old) {
// 	if (i == -1) return n + 2;
// 	if (i == n + 1) return 0;
// 	ll& ret = memo[i][old];
// 	if (~ret) return ret;

// 	ret = n + 2;
// 	if (nxt[i][0] != i) ret = min(ret, 1 + solve(nxt[i][0], 0));
// 	if (nxt[i][1] != i && !old) ret = min(ret, 1 + solve(nxt[i][1], 1));
// 	return ret;
// }

int main() {
	rd(n, m);
	N = n + 1;

	a[0] = 1;
	a[n+1] = m;
	for (int i = 1; i <= n; i++) rd(a[i]);
	rd(x, y);

	for (int i = 0; i <= n; i++) {
		nxt[i][0] = prev(upper_bound(a, a+n+2, a[i] + x)) - a;
		nxt[i][1] = prev(upper_bound(a, a+n+2, a[i] + y)) - a;
	}

	mset(seg, 0x3f);
	update(1, 1, N, n+1, 0, 0);
	update(1, 1, N, n+1, 0, 1);

	for (int i = n; i >= 0; i--) {
		memo[i][0] = memo[i][1] = 1 + query(1, 1, N, i+1, nxt[i][0], 0);
		memo[i][0] = min(memo[i][0], 1 + query(1, 1, N, i+1, nxt[i][1], 1));
		update(1, 1, N, i, memo[i][0], 0);
		update(1, 1, N, i, memo[i][1], 1);
	}

	printf("%lld\n", memo[0][0] <= n+1 ? memo[0][0] : -1);
}