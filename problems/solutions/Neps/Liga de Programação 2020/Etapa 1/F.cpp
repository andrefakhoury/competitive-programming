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
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int n; // number of nodes
vector<int> edges[MAXN];

vector<bool> vis;
vector<int> tin, low;
int timer;

set<pii> bridges;

void dfs(int u, int p = -1) {
	vis[u] = true;
	tin[u] = low[u] = timer++;
	for (int v : edges[u]) if (v != p) {
		if (vis[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) {
				bridges.emplace(u, v);
				bridges.emplace(v, u);
			}
		}
	}
}

pii solve(int u) {
	vis[u] = true;

	vector<pii> vec;
	pii ans = {0, 0};

	for (int v : edges[u]) if (!vis[v]) {
		pii cur = solve(v);
		cur.fi += bridges.count({u, v});
		vec.eb(cur);
		ans.fi = max(ans.fi, cur.fi);
		ans.se = max(ans.se, cur.se);
	}

	sort(vec.rbegin(), vec.rend());
	if (vec.size() > 1u) ans.se = max(ans.se, vec[0].fi + vec[1].fi);
	else if (vec.size()) ans.se = max(ans.se, vec.front().fi);
	
	return ans;
}

void find_bridges() {
	timer = 0;
	vis.assign(n, false);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; i++)
		if (!vis[i]) dfs(i);
}

int main() {
	rd(n);
	int m; rd(m);

	for (int i = 1; i <= m; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	find_bridges();
	vis.assign(n, false);
	int ans = solve(0).second;
	printf("%d\n", ans);
}