/*
ID: fakhoury
LANG: C++11
TASK: fcolor
*/

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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
int siz[MAXN];
int par[MAXN];
int pos[MAXN];

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

inline bool cmp(int const& u, int const& v) {
	return pos[u] < pos[v];
}

inline void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;

	if (siz[u] > siz[v]) swap(u, v);


	for (int xx : edges[u]) edges[v].pb(xx);
	par[u] = v;
	siz[v] += siz[u];

	int yy = *edges[v].begin();
	for (int xx : edges[u]) {
		if (par[xx] != par[yy])
			merge(xx, yy);
	}

	edges[u].clear();
}

int color[MAXN];

vector<int> revr[MAXN];

bool vis[MAXN];
vector<int> order;
void dfsOrder(int u) {
	vis[u] = true;
	for (int v : revr[u])
		if (!vis[v]) dfsOrder(v);
	order.pb(u);
}

int main() {
#ifndef LOCAL_PC
	freopen("fcolor.in", "r", stdin);
	freopen("fcolor.out", "w", stdout);
#endif

	int n, m; rd(n, m);
	for (int i = 1; i <= m; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		
		revr[v].pb(u);
		revr[u].pb(v);
	}

	for (int i = 1; i <= n; i++) {
		par[i] = i;
		siz[i] = 1;
	}

	for (int u = 1; u <= n; u++)
		if (!vis[u]) dfsOrder(u);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++) pos[order[i]] = i;
	for (int i= 1; i <= n; i++) {
		sort(edges[i].begin(), edges[i].end(), cmp);
	}

	for (int i : order) {
		if (edges[i].empty()) continue;
		int u = *edges[i].begin();
		vector<pii> mrg;
		for (int v : edges[i]) mrg.eb(u, v);
		for (auto p : mrg) merge(p.fi, p.se);
	}

	int curColor = 0;
	for (int i = 1; i <= n; i++) {
		int x = find(i);
		if (!color[x]) color[x] = ++curColor;
		printf("%d\n", color[x]);
	}
}