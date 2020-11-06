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

const int MAXN = 2e3 + 5, INF = 0x3f3f3f3f;

int d[MAXN][MAXN];
vector<pii> edges[MAXN];

inline void IMP() {
	cout << "NO\n";
	exit(0);
}

/** Disjoint Set Union, aka Union Find */
class DSU {
public:
	int n;
	std::vector<int> par;
	std::vector<int> sz;

	// Union Find with path compression and union by size
	// operations in O(alpha(n)), where alpha is the inverse Ackermann
	DSU(int n) : n(n) {
		par.resize(n + 1);
		sz = std::vector<int>(n + 1, 1);
		iota(par.begin(), par.end(), 0);
	}

	// find leader of current component
	// if necessary, remind to remove the path compression
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}

	// merge two componnets
	// returns whether they dont already belong to the same
	inline bool merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) std::swap(u, v);
		par[u] = v;
		sz[v] += sz[u];
		return true;
	}
};

void dfs(int u, int p, int ini, ll cur, ll* dd) {
	dd[u] = cur;
	for (pii ed : edges[u]) if (ed.se != p) {
		dfs(ed.se, u, ini, cur + ed.fi, dd);
	}
}

ll dist[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> d[i][j];

	vector<pair<int, pii>> v;
	for (int i = 1; i <= n; i++) {
		if (d[i][i] != 0) IMP();

		for (int j = 1; j <= n; j++) {
			if (d[i][j] != d[j][i]) IMP();
			v.eb(d[i][j], mk(i, j));
		}
	}

	sort(v.begin(), v.end());

	DSU uf(n);
	for (auto p : v) {
		int w = p.fi;
		int v1 = p.se.fi, v2 = p.se.se;
		if (uf.find(v1) != uf.find(v2)) {
			uf.merge(v1, v2);
			if (w <= 0) IMP();
			edges[v1].eb(w, v2);
			edges[v2].eb(w, v1);
		}
	}

	mset(dist, 0x3f);
	for (int i = 1; i <= n; i++) dfs(i, i, i, 0, dist[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] != dist[i][j]) {
				IMP();
			}
		}
	}

	cout << "YES\n";
}