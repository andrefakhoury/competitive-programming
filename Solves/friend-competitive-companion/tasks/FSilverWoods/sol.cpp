#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
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
const double EPS = 1e-9;

int par[MAXN];

int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
void merge(int u, int v) { par[find(u)] = find(v); }

inline bool can(double R, int n, vector<pii>& a) {
	const int UP = n, DOWN = n + 1;
	iota(par, par+n+2, 0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (hypot(a[i].fi - a[j].fi, a[i].se - a[j].se) < 2 * R) {
				merge(i, j);
			}
		}
		if (a[i].se + 2 * R > 100) merge(i, UP);
		if (a[i].se - 2 * R < -100) merge(i, DOWN);
	}
	return find(UP) != find(DOWN);
}

int main() {
	int n; rd(n);

	vector<pii> in(n);
	for (int i = 0; i < n; i++) {
		rd(in[i].fi, in[i].se);
	}
	sort(in.begin(), in.end(), [](pii a, pii b) {
		return a.se < b.se;
	});

	double lo = 0, hi = 100, mi;
	int cnt = 100;
	while(hi - lo > EPS && cnt--) {
		mi = 0.5 * (hi + lo);
		if (can(mi, n, in)) lo = mi;
		else hi = mi;
	}
	printf("%.20lf\n", lo);
}