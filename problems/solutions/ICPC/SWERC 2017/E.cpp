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
#ifndef __linux
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

const int MAXN = 2e5 + 5, MAXM = 1e4 + 5, INF = 0x3f3f3f3f;

char aux[25];
vector<tuple<int, int, int>> edges[MAXN];

pii cost[MAXN];

int memo[MAXM];

inline pii solve(int n, int B) {
	mset(memo, -1);
	memo[0] = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int w = cost[i].fi;
		int r = cost[i].se;

		for (int j = B-w; j >= 0; j--) {
			memo[j + w] = max(memo[j + w], memo[j] + r);
			ans = max(ans, memo[j + w]);
		}
	}

	int ans2 = INF;
	for (int i = 0; i < MAXM; i++)
		if (memo[i] == ans) ans2 = min(ans2, i);

	return {ans, ans2};
	
}

int main() {
	int B; rd(B);
	int n; rd(n);

	map<string, int> idx;
	int cur_index = 0;

	auto get_index = [&](string s) {
		if (idx.count(s)) return idx[s];
		return idx[s] = cur_index++;
	};

	for (int i = 1; i <= n; i++) {
		int u, v, a, b;
		scanf(" %s", aux);
		u = get_index(string(aux));
		scanf(" %s", aux);
		v = get_index(string(aux));
		scanf(" %*s");
		rd(a, b);

		edges[u].emplace_back(v, a, b);
	};

	vector<int> ord;
	vector<bool> vis(cur_index);
	auto dfs_topo = [&](auto&& dfs_topo, int u)->void {
		vis[u] = true;
		for (auto [v, a, b] : edges[u]) if (!vis[v])
			dfs_topo(dfs_topo, v);
		ord.push_back(u);
	};

	for (int i = 0; i < cur_index; i++) if (!vis[i])
		dfs_topo(dfs_topo, i);


	auto add = [](pii a, int x, int y) {
		a.fi += x;
		a.se += y;
		return a;
	};

	auto best = [](pii a, pii b) {
		if (a.fi == b.fi) return max(a, b);
		else return min(a, b);
	};

	for (int i : ord) {
		if (edges[i].empty()) cost[i] = {0, 0};
		else {
			cost[i] = {INF, INF};
			for (auto [v, a, b] : edges[i]) {
				cost[i] = best(cost[i], add(cost[v], a, b));
			}
		}
	}

	pii ans = solve(cur_index, B);
	printf("%d\n%d\n", ans.fi, ans.se);
}