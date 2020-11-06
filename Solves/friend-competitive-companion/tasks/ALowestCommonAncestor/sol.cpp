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
int level[MAXN];
vector<int> edges[MAXN];

void dfs(int u, int p) {
	par[u][0] = p;
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		edges[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> edges[i][j];
		}
	}
	dfs(0, 0);

	for (int b = 1; b < LOG; b++) {
		for (int u = 0; u < n; u++) {
			par[u][b] = par[par[u][b - 1]][b - 1];
		}
	}

	auto lca = [&](int u, int v) {
		if (level[u] < level[v]) swap(u, v);
		for (int b = LOG-1; b >= 0; b--) {
			if ((level[u] - (1 << b)) >= level[v])
				u = par[u][b];
		}
		if (u == v) return u;
		for (int b = LOG-1; b >= 0; b--)
			if (par[u][b] != par[v][b])
				u = par[u][b], v = par[v][b];
		return par[u][0];
	};

	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;
		cout << lca(u, v) << "\n";
	}

}