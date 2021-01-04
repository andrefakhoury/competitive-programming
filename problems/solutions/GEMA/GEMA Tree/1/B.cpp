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

const int MAXN = 2e5 + 10, INF = 0x3f3f3f3f;
const int MAXL = 21;

vector<pii> edges[MAXN];
vector<int> all;
vector<pii> need[MAXN];
int level[MAXN];
int bt[MAXN];
int cur_time;
int ent[MAXN];
int sai[MAXN];
int euler[MAXN];
int par[MAXN][MAXL];

inline void init() {
	for (int i = 0; i < MAXN; i++) {
		edges[i].clear();
		need[i].clear();
	}
	memset(ent, 0, sizeof ent);
	memset(sai, 0, sizeof sai);
	memset(euler, 0, sizeof euler);
	memset(par, 0, sizeof par);
	memset(bt, 0, sizeof bt);
	memset(level, 0, sizeof level);
	cur_time = 0;
	all.clear();
}
void dfs(int u, int pu = 0, int w = 0) {
	ent[u] = cur_time;

	for (pii& p : edges[u]) if (p.fi != pu) {
		par[p.fi][0] = u;
		euler[++cur_time] = p.se;
		level[p.fi] = level[u] + 1;
		dfs(p.fi, u, p.se);
	}

	sai[u] = ++cur_time;
	euler[cur_time] = w;
}

inline int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
	for (int b = MAXL-1; ~b; b--)
		if (level[u] - (1 << b) >= level[v])
			u = par[u][b];
	if (u == v) return u;
	for (int b = MAXL-1; ~b; b--) {
		if (par[u][b] != par[v][b]) {
			u = par[u][b];
			v = par[v][b];
		}
	}

	return par[u][0];
}

inline void update(int i, int k) {
	i++;
	while(i < MAXN) {
		bt[i] ^= k;
		i += i&-i;
	}
}

inline int query(int i) {
	int ret = 0;
	i++;
	while(i) {
		ret ^= bt[i];
		i -= i&-i;
	}
	return ret;
}

inline void query(int u, int v, int k, int id) {
	// euler[ini[v]..ini[u]]
	need[sai[v]-1].eb(k, id);
	need[ent[u]].eb(k, id);
}

int main() {
	int __T__; rd(__T__);
	while(__T__--) {
		int n; rd(n);

		for (int i = 1; i < n; i++) {
			int u, v, w; rd(u, v, w);
			edges[u].eb(v, w);
			edges[v].eb(u, w);
			all.eb(w);
		}

		dfs(1);
		for (int i = 1; i < MAXL; i++)
			for (int u = 1; u <= n; u++)
				par[u][i] = par[par[u][i-1]][i-1];

		int q; rd(q);
		vector<int> ans(q);
		for (int i = 0; i < q; i++) {
			int u, v, k; cin >> u >> v >> k;
			int l = lca(u, v);
			query(u, l, k, i);
			query(v, l, k, i);
		}
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());

		for (int i = 1; i < MAXN; i++) {
			int idx = lower_bound(all.begin(), all.end(), euler[i]) - all.begin();
			update(idx, euler[i]);

			for (pii& p : need[i]) {
				int K = p.fi;
				auto it = upper_bound(all.begin(), all.end(), K);
				if (it == all.begin()) continue;
				ans[p.se] ^= query(it - all.begin() - 1);
			}
		}

		for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
		if (__T__) init();
	}

	return 0;
}