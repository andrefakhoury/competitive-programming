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
using pii = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

ll memo[76][76][2];

struct Stt {
	int i, q, f, g;
} nxt[76][76][2];

ll solve(int i, int q, int f, vector<pair<pii, int>>& a, int n, int k) {
	if (i == n) {
		if (q < k-1) return -INF;
		return 0;
	}

	ll& ret = memo[i][q][f];
	if (~ret) return ret;

	Stt& nx0 = nxt[i][q][f];

	ret = solve(i+1, q, f, a, n, k);
	nx0 = {i+1, q, f, 0};

	if (q < k-1) {
		ll cur = a[i].fi.fi + a[i].fi.se * q + solve(i+1, q+1, f, a, n, k);
		if (cur >= ret) {
			ret = cur;
			nx0 = {i+1, q+1, f, 1};
		}
	}

	{
		ll cur = a[i].fi.se*(k-1) + solve(i+1, q, f, a, n, k);
		if (cur >= ret) {
			ret = cur;
			nx0 = {i+1, q, f, 2};
		}
	}

	if (!f) {
		ll cur = a[i].fi.fi + a[i].fi.se*(k-1) + solve(i+1, q, 1, a, n, k);
		if (cur >= ret) {
			ret = cur;
			nx0 = {i+1, q, 1, 3};
		}
	}

	return ret;
}

inline void _solve_(int __ntest__) {
	int n, k; rd(n, k);
	vector<pair<pii, int>> a(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi.fi, a[i].fi.se);
		a[i].se = i;
	}

	sort(a.begin(), a.end(), [](pair<pii, int> x, pair<pii, int> y) {
		return x.fi.se < y.fi.se;
	});
	
	memset(memo, -1, sizeof memo);
	solve(0, 0, 0, a, n, k);

	auto tp = [](int& a, int& b, int& c, Stt st) {
		int x = st.i;
		int y = st.q;
		int z = st.f;
		a = x, b = y, c = z;
	};

	vector<int> g[4];
	for (int i = 0, j = 0, t = 0; i < n; tp(i, j, t, nxt[i][j][t]))
		g[nxt[i][j][t].g].eb(a[i].se+1);
	assert(g[3].size() == 1u);

	vector<int> ans;
	for (int i : g[1]) ans.eb(i);
	for (int i : g[2]) ans.eb(i), ans.eb(-i);
	for (int i : g[3]) ans.eb(i);

	
	printf("%ld\n", ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}