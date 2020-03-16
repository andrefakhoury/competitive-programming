#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;
const int MAXL = 21;

vector<int> edges[MAXN];

int par[MAXN][MAXN][MAXL]; // par[u][2^i]
int level[MAXN][MAXN];

set<int> leafs;

void dfs(int u, int rr) {
	int cnt = 0;
	for (int v : edges[u]) {
		if (level[rr][v] == -1) {
			par[rr][v][0] = u;
			level[rr][v] = level[rr][u] + 1;
			dfs(v, rr);
			cnt++;
		}
	}
	if (cnt == 0) leafs.emplace(u);
}

/** Returns the LCA of u and v */
int lca(int u, int v, int rr) {
	if (level[rr][u] < level[rr][v]) swap(u, v);
 
	for (int i = MAXL-1; i >= 0; i--) {
		if (level[rr][u] - (1 << i) >= level[rr][v]) {
			u = par[rr][u][i];
		}
	}
 
	if (u == v) return u;
 
	for (int i = MAXL-1; i >= 0; i--) {
		if (par[rr][u][i] != par[rr][v][i]) { 
			u = par[rr][u][i];
			v = par[rr][v][i];
		}
	}

	return par[rr][u][0];
}

/** Preprocess the levels and stuff */
void pre(int n) {
	memset(level, -1, sizeof level);

	for (int root = 1; root <= n; root++) {
		level[root][root] = 0;
		dfs(root, root);
		for (int i = 1; i < MAXL; i++) {
			for (int u = 1; u <= n; u++) {
				par[root][u][i] = par[root][par[root][u][i-1]][i-1];
			}
		}
	}
}

inline int ask(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

inline void guess(int u) {
	printf("! %d\n", u);
	fflush(stdout);
	exit(0);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	pre(n);

	for (int i : leafs) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}