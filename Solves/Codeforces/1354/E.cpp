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

const int MAXN = 5e3 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];
vector<int> same[MAXN];
vector<pii> pos;
int vis[MAXN];

inline void imp(int flag = -1) {
	puts("NO");
	exit(0);
}

pii dfs(int u, int c, int p) {
	if (vis[u] && vis[u] != c) imp(1);
	else if (vis[u]) return {0, 0};
	vis[u] = c;
	same[p].eb(u);

	pii ret{0, 0};
	if (c == 1) ret.fi++;
	else ret.se++;

	for (int v : edges[u]) {
		pii cur = dfs(v, 3-c, p);
		ret.fi += cur.fi;
		ret.se += cur.se;
	}

	return ret;
}

int memo[MAXN][MAXN];
int nxt[MAXN][MAXN];
int ans[MAXN];

bool solve(int i, int k) {
	if (k < 0) return false;

	if (i == (int) pos.size()) {
		return k == 0;
	}

	int& ret = memo[i][k];
	if (~ret) return ret;

	if (solve(i+1, k - pos[i].fi)) {
		nxt[i][k] = 1;
		ret = 1;
	} else if (solve(i+1, k - pos[i].se)) {
		nxt[i][k] = 2;
		ret = 1;
	} else ret = 0;

	return ret;
}

int main() {
	int n, m; rd(n, m);
	int n1, n2, n3; rd(n1, n2, n3);
	int qtt[4] = {0, n1, n2, n3};
	
	for (int i = 1; i <= m; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) {
		pos.eb(dfs(i, 1, pos.size()));
	}

	memset(memo, -1, sizeof memo);
	if (!solve(0, qtt[2])) imp(3);

	for (int i = 0, j = qtt[2]; i < (int) pos.size(); i++) {
		for (int u : same[i]) {
			ans[u] = vis[u];
			if (nxt[i][j] == 1) ans[u] = 3 - ans[u];
		}

		if (nxt[i][j] == 1) j -= pos[i].fi;
		else j -= pos[i].se;
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1)
			ans[i] = qtt[1] ? 1 : 3;
		qtt[ans[i]]--;
		if (qtt[ans[i]] < 0) imp(4);
	}

	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d", ans[i]);
	printf("\n");

}