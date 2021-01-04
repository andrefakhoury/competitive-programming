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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

vector<int> edg[MAXN];
vector<int> rev[MAXN];
vector<int> sd[MAXN];

int tim[MAXN];
int inv_tim[MAXN];
int par[MAXN];
int sdom[MAXN];
int idom[MAXN];
int un[MAXN];
int path[MAXN];

pii query(int u) {
	if (u == un[u]) return {u, u};
	int p;
	tie(p, un[u]) = query(un[u]);
	if (sdom[p] < sdom[path[u]]) path[u] = p;
	return {path[u], un[u]};
}

int tt;
void dfs(int u) {
	tim[u] = ++tt;
	inv_tim[tt] = u;
	for (int v : edg[u]) {
		if (!tim[v]) {
			dfs(v);
			par[tim[v]] = tim[u];
		}
	}
}

void build() {
	for (int u = 1; u <= tt; u++) sdom[u] = idom[u] = un[u] = path[u] = u;
	for (int u = tt; u >= 1; u--) {
		for (int v : rev[inv_tim[u]]) {
			v = tim[v];
			if (v == 0) continue;
			if (v < u) sdom[u] = min(sdom[u], sdom[v]);
			else sdom[u] = min(sdom[u], sdom[query(v).fi]);
		}
		sd[sdom[u]].pb(u);

		for (int v : sd[u]) {
			int best = query(v).fi;
			if (sdom[best] >= u) idom[v] = u;
			else idom[v] = best;
		}

		for (int v : edg[inv_tim[u]]) {
			v = tim[v];
			if (v == 0) continue;
			if (par[v] == u) un[v] = u;
		}
	}

	for (int u = 1; u <= tt; u++) {
		if (idom[u] != sdom[u]) idom[u] = idom[idom[u]];
	}
}


vector<int> edtree[MAXN];
int sz[MAXN];

int pre(int u, int p) {
	sz[u] = 1;
	for (int v : edtree[u]) if (v != p)
		sz[u] += pre(v, u);
	return sz[u];
}

ll solve(int u, int& n, int p, int who) {
	ll ans = 0;
	for (int v : edtree[u]) if (v != p) {

		if (u == 1) {
			ans += solve(v, n, u, v);
		} else {
			ans += solve(v, n, u, who);
		}
	}
	
	ans += n - sz[who];

	return ans;
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			edg[u].eb(v);
			rev[v].pb(u);
		}

		dfs(1);
		build();

		for (int i = 1; i <= n; i++) {
			edtree[inv_tim[idom[tim[i]]]].eb(i);
		}

		sz[0] = 1;
		pre(1, 1);
		printf("%lld\n", solve(1, n, 1, 0) / 2);

		tt = 0;
		for (int i = 0; i < MAXN; i++) {
			edtree[i].clear();
			edg[i].clear();
			rev[i].clear();
			sd[i].clear();
			tim[i] = 0;
			inv_tim[i] = 0;
			par[i] = 0;
			sdom[i] = 0;
			idom[i] = 0;
			un[i] = 0;
			path[i] = 0;
		}
	}
}