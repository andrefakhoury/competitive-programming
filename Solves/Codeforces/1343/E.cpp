#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
int dist[MAXN];
int par[MAXN];
int frq[MAXN];

inline void bfs(int S) {
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.emplace(S);
	dist[S] = 0;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int v : edges[u]) if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			par[v] = u;
			q.emplace(v);
		}
	}
}

inline void _solve_(int __ntest__) {
	int n, m, a, b, c; rd(n, m, a, b, c);
	vector<ll> prices(m);
	for (ll& i : prices) rd(i);

	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	bfs(b);
	while(a != b) frq[a]++, a = par[a];
	while(c != b) frq[c]++, c = par[c];

	sort(prices.begin(), prices.end());
	sort(frq+1, frq+n+1, greater<int>());

	ll ans = 0;
	for (int i = 1, j = 0; i <= n; i++)
		if (frq[i]) ans += prices[j++] * frq[i];
	printf("%lld\n", ans);

	for (int i = 1; i <= n; i++) {
		dist[i] = par[i] = frq[i] = 0;
		edges[i].clear();
	}
}

int main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}