#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e3 + 5;
int n, m;

char grid[MAXN][MAXN];
int f[MAXN][MAXN];

vector<pii> edges[MAXN][MAXN];
vector<pii> invrs[MAXN][MAXN];
int color[MAXN][MAXN];
vector<pii> sameColor[MAXN * MAXN];
bool vis[MAXN][MAXN];
vector<pii> order;
int memo[MAXN * MAXN];
bool visColor[MAXN * MAXN];
unordered_set<int> edgesColor[MAXN * MAXN];

pii corres(char c, int i, int j) {
	if (c == 'N') return mp(i-1, j);
	if (c == 'S') return mp(i+1, j);
	if (c == 'E') return mp(i, j+1);
	return mp(i, j-1);
}

void dfsOrder(int i, int j) {
	vis[i][j] = true;

	for (pii& v : edges[i][j]) {
		if (!vis[v.fi][v.se]) dfsOrder(v.fi, v.se);
	}

	order.pb(mp(i, j));
}

void dfsColor(int i, int j, int curColor) {
	color[i][j] = curColor;
	sameColor[curColor].pb(mp(i,j));

	for (pii& v : invrs[i][j])
		if (!color[v.fi][v.se]) dfsColor(v.fi, v.se, curColor);
}

bool containsBorder(int cor) {
	for (pii& u : sameColor[cor]) {
		pii v = corres(grid[u.fi][u.se], u.fi, u.se);

		if (v.fi == 0 || v.fi > n || v.se == 0 || v.se > m)
			return true;
	}
	return false;
}

int dfsAnswer(int u) {
	if (memo[u]) return memo[u];
	visColor[u] = true;

	int current = 0;
	for (int v : edgesColor[u]) {
		current += dfsAnswer(v);
	}

	return memo[u] = 1 + current;
} 

void scc() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j]) dfsOrder(i, j);

	reverse(order.begin(), order.end());

	int curColor = 0;
	for (pii& u : order) {
		if (!color[u.fi][u.se]) dfsColor(u.fi, u.se, ++curColor);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int u1 = color[i][j];

			for (pii& p : edges[i][j]) {
				edgesColor[u1].insert(color[p.fi][p.se]);
			}
		}
	}

	for (int c = 1; c <= curColor; c++) {
		if (containsBorder(c)) {
			memo[c] = 1;
		}

		if (sameColor[c].size() > 1)
			memo[c] = sameColor[c].size();
	}

	for (int c = 1; c <= curColor; c++) {
		if (!memo[c]) dfsAnswer(c);

		for (pii& u : sameColor[c]) {
			f[u.fi][u.se] = memo[c];
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &grid[i][j]);

			pii C = corres(grid[i][j], i, j);
			edges[i][j].pb(C);
			invrs[C.fi][C.se].pb(mp(i,j));
		}
	}

	scc();

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += f[i][j];
			assert(f[i][j] != 0);
		}
	}

	printf("%lld\n", ans);
}