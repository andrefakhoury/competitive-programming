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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

const int LOG = 21;

int par[MAXN][LOG];
int mn[MAXN][LOG];
int mx[MAXN][LOG];
int level[MAXN];
vector<pii> edges[MAXN];

void dfs(int u, int p) {
	par[u][0] = p;
	for (pii ed : edges[u]) if (ed.fi != p) {
			int v = ed.fi, w = ed.se;
			mn[v][0] = w;
			mx[v][0] = w;
			level[v] = level[u] + 1;
			dfs(v, u);
		}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges[u].eb(v, w);
		edges[v].eb(u, w);
	}
	mset(mn, 0x3f);
	dfs(1, 1);

	for (int b = 1; b < LOG; b++) {
		for (int u = 1; u <= n; u++) {
			par[u][b] = par[par[u][b - 1]][b - 1];
			mn[u][b] = min(mn[u][b-1], mn[par[u][b-1]][b-1]);
			mx[u][b] = max(mx[u][b-1], mx[par[u][b-1]][b-1]);
		}
	}

	auto lca = [&](int u, int v)->tuple<int, int, int> {
		if (level[u] < level[v]) swap(u, v);

		int mini = 0x3f3f3f3f, maxi = 0;
		auto lift = [&](int& u, int b) {
			mini = min(mini, mn[u][b]);
			maxi = max(maxi, mx[u][b]);
			u = par[u][b];
		};

		for (int b = LOG-1; b >= 0; b--)
			if ((level[u] - (1 << b)) >= level[v])
				lift(u, b);
		if (u == v) return {u, mini, maxi};

		for (int b = LOG-1; b >= 0; b--) {
			if (par[u][b] != par[v][b]) {
				lift(u, b);
				lift(v, b);
			}
		}

		lift(u, 0);
		lift(v, 0);
		return {u, mini, maxi};
	};

	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;
		auto ans = lca(u, v);

		cout << get<1>(ans) << " " << get<2>(ans) << "\n";
	}

}