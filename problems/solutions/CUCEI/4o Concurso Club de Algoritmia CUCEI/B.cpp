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

const int MAXN = 5e4 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
int _c[MAXN];
int c[MAXN];

void prep(int k) {
	c[0] = 0;
	for (int i = 1; i <= k; i++) {
		c[i] = _c[i];
		for (int j = 1; j < i; j++) {
			c[i] = min(c[i], c[j] + c[i-j]);
		}
	}
}

int level[MAXN];
int par[MAXN][21];
void dfslca(int u, int p) {
	par[u][0] = p;
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		dfslca(v, u);
	}
}

int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
	for (int b = 20; ~b; b--) {
		if (level[u] - (1 << b) >= level[v]) u = par[u][b];
	}
	if (u == v) return u;
	for (int b = 20; ~b; b--) {
		if (par[u][b] != par[v][b]) u = par[u][b], v = par[v][b];
	}
	return par[u][0];
}


int main() {
	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	dfslca(1, 1);
	for (int b = 1; b < 21; b++)
		for (int u = 1; u <= n; u++)
			par[u][b] = par[par[u][b-1]][b-1];

	int T; rd(T);
	while(T--) {
		int K; rd(K);
		map<int, int> f;
		for (int i = 0, x; i < K; i++) rd(x), f[x]++;
		map<int, int> ls;
		vector<pii> F;
		for (auto p : f) F.eb(p.fi, p.se);
		for (int i = 0; i < (int) F.size(); i++) {
			set<int> all;
			for (int j = 0; j < (int) F.size(); j++) all.insert(lca(F[i].fi, F[j].fi));
			for (int j : all) ls[j] += F[i].se;
		}

		vector<pii> allv;
		for (auto p : ls) allv.eb(p.fi, p.se);
		sort(allv.begin(), allv.end(), [&](pii a, pii b) { return level[a.fi] > level[b.fi]; });

		for (int i = 1; i <= K; i++) rd(_c[i]);
		prep(K);

		ll ans = 0;
		for (auto [u, cnt] : allv) {
//			DBG(u, cnt);
			int qtEdges = level[u];
			for (auto [v, cnt2] : allv) if (u != v && lca(u, v) == v) {
				qtEdges = min(qtEdges, level[u] - level[v]);
			}
			ans += 1ll * qtEdges * c[cnt];
		}
		printf("%lld\n", ans);
	}
}
