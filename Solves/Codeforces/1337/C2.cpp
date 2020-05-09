#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
bool chosen[MAXN];
int dist[MAXN];
int qtt[MAXN], sz[MAXN];

ll solve(int u, int p = -1, int q = 0) {
	ll ret = 0;
	if (!chosen[u]) ret += q;
	else q++;

	for (int v : edges[u]) if (v != p) {
		ret += solve(v, u, q);
	}

	return ret;
}

void dfs_qtt(int u, int p = -1, int q = 0) {
	qtt[u] = q;
	for (int v : edges[u]) if (v != p)
		dfs_qtt(v, u, q + 1);
}

int dfs_sz(int u, int p = -1) {
	sz[u] = 1;
	for (int v : edges[u]) if (v != p)
		sz[u] += dfs_sz(v, u);
	return sz[u];
}

int main() {
	int n, k; rd(n, k);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	dfs_sz(1);
	dfs_qtt(1);

	priority_queue<pair<pair<ll, ll>, int>> pq; pq.emplace(mk(0, 0), 1);
	int lft = n - k;
	memset(dist, 0x3f, sizeof dist);

	while(lft--) {
		int u = pq.top().se;
		dist[u] = 0;
		chosen[u] = 1;
		pq.pop();

		for (int v : edges[u]) if (dist[v]) {
			pq.emplace(mk(ll(sz[v]-1) * qtt[v] - qtt[v], 0), v);
		}
	}

	printf("%lld\n", solve(1));
}