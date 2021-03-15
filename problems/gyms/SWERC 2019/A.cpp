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

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

struct Point {
	int x, y;
} loc[MAXN];

int C[MAXN];
int B, T, N;
vector<pii> edges[MAXN];

ll memo[MAXN][105];

ll dist(int i, int j) {
	ll xx = (loc[i].x - loc[j].x) * (loc[i].x - loc[j].x);
	xx   += (loc[i].y - loc[j].y) * (loc[i].y - loc[j].y);

	ll lo = 0, hi = 1e4, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (mi * mi >= xx) hi = mi;
		else lo = mi + 1;
	}

	return hi;
}

ll solve(int i, int B) {
	if (B < 0) return INF;
	if (i == N + 1) return 0;

	ll& ret = memo[i][B];
	if (~ret) return ret;

	ret = INF;
	for (auto p : edges[i]) {
		if (i == p.fi) continue;

		// vou para p.fi usando p.se
		ll dd = dist(i, p.fi);
		ret = min(ret, dd * C[p.se] + solve(p.fi, B - dd));
	}

	return ret;
}

int main() {
	rd(loc[0].x, loc[0].y);
	Point dest; rd(dest.x, dest.y);

	rd(B);
	rd(C[0]);
	rd(T);
	for (int i = 1; i <= T; i++) rd(C[i]);

	rd(N);
	loc[N+1] = dest;

	for (int i = 1; i <= N; i++) {
		rd(loc[i].x, loc[i].y);
		int l; rd(l);

		for (int j = 0; j < l; j++) {
			int u, v; rd(u, v);
			u++;
			edges[i].eb(u, v);
			edges[u].eb(i, v);
		}
	}

	for (int i = 1; i <= N+1; i++) edges[0].eb(i, 0);
	for (int i = 0; i <= N;   i++) edges[i].eb(N+1, 0);

	memset(memo, -1, sizeof memo);
	ll ans = solve(0, B);
	printf("%lld\n", ans < INF ? ans : -1);	
}