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

const int MAXN = 100 + 1, INF = 0x3f3f3f3f;

int x[3];
int n, m;
int memcan[51][51][101];
vector<int> xs;
vector<int> edges[51];

bool can(int u, int v, int d) {
	if (d < 0) return false;
	if (d == 0) return u == v;

	int& ret = memcan[u][v][d];
	if (~ret) return ret;

	ret = 0;
	for (int k : edges[u])
		ret |= can(k, v, d-1);
	return ret;
}

int memo[MAXN][MAXN];
int solve(int u, int d) {
	if (u == n) return d;
	if (d == MAXN) return INF;

	int& ret = memo[u][d];
	if (~ret) return ret;

	ret = -1;
	for (int i = 0; i < 3; i++) {
		int cur = INF;
		for (int v = 1; v <= n; v++) if (v != u && can(u, v, x[i])) {
			cur = min(cur, solve(v, d+1));
		}
		ret = max(ret, cur);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", x+0, x+1, x+2);

	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
	}

	mset(memcan, -1);
	mset(memo, -1);

	int ans = solve(1, 0);
	if (ans < INF) printf("%d\n", ans);
	else puts("IMPOSSIBLE");
}