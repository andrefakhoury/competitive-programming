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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

int par[MAXN][21];
int level[MAXN];
vector<int> edges[MAXN];

void dfs(int u, int p = -1) {
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u]+1;
		par[v][0] = u;
		dfs(v, u);
	}
}

inline int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
 
	for (int i = 20; i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
			u = par[u][i];
 
	if (u == v) return u;
 
	for (int i = 20; i >= 0; i--) {
		if (par[u][i] != par[v][i]) { 
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

vector<int> vec[MAXN];
vector<pii> ini[MAXN];
int pos[MAXN][MAXN];
int memo[MAXN][MAXN];

vector<int> getway(int u, int v) {
	vector<int> ret;
	while(true) {
		ret.eb(u);
		if (u == v) break;
		u = par[u][0];
	}
	return ret;
}

int solve(int i, int at) {
	if (i == (int) vec[at].size()) return 0;

	int& ret = memo[i][at];
	if (~ret) return ret;

	ret = 1 + solve(i+1, at);
	for (auto k : ini[vec[at][i]]) if (k.se != at) {
		if (pos[at][k.fi] != -1 && pos[at][k.fi] >= i) {
			ret = min(ret, 1 + solve(pos[at][k.fi]+1, at));
		}
	}

	return ret;
}

int main() {
	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	dfs(1);

	for (int b = 1; b <= 20; b++) {
		for (int u = 1; u <= n; u++) {
			par[u][b] = par[par[u][b-1]][b-1];
		}
	}

	memset(pos, -1, sizeof pos);

	int r; rd(r);
	for (int i = 1; i <= r; i++) {
		int a, b; rd(a, b);
		int l = lca(a, b);

		vec[i] = getway(a, l);
		vec[i].pop_back();
		vector<int> cur = getway(b, l);
		reverse(cur.begin(), cur.end());
		for (int x : cur) vec[i].pb(x);

		ini[vec[i].front()].eb(vec[i].back(), i);

		for (int j = 0; j < (int) vec[i].size(); j++) {
			pos[i][vec[i][j]] = j;
		}
	}

	memset(memo, -1, sizeof memo);

	int ans = 0;
	for (int i = 1; i <= r; i++) {
		ans += solve(0, i);
	}

	printf("%d\n", ans);	
}