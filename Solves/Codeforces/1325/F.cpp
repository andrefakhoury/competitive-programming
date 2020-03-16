#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int sqr;

vector<int> edges[MAXN];
set<int> st;

int color[MAXN];
pii mark[MAXN];
int par[MAXN];
vector<int> cycle;

void dfs_bicolor(int u) {
	bool can = true;
	for (int v : edges[u]) can &= color[v] != 1;
	if (can) {
		color[u] = 1;
		st.emplace(u);
	} else color[u] = 2;

	for (int v : edges[u])
		if (!color[v]) dfs_bicolor(v);
}

bool dfs_cycle(int u, int p) { 
	if (color[u] == 2) return false;

	if (color[u] == 1) {
		cycle.clear();
		cycle.pb(u);
		for (int cur = p; cur != u; cur = par[cur])
			cycle.pb(cur);
		return (int)cycle.size() >= sqr;
	}

	color[u] = 1;
	par[u] = p;
	shuffle(edges[u].begin(), edges[u].end(), rng);
	for (int v : edges[u]) if (v != p) {
		if (dfs_cycle(v, u)) return true;
	}

	color[u] = 2;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		edges[u].pb(v);
		edges[v].pb(u);
	}

	sqr = 1;
	while(sqr * sqr < n) sqr++;

	while (true) {
		memset(color, 0, sizeof color);
		st.clear();
		dfs_bicolor(rng()%n+1);
		if ((int)st.size() >= sqr) {
			cout << 1 << '\n';
			while(sqr--) {
				cout << *st.begin() << ' ';
				st.erase(st.begin());
			}
			cout << '\n';
			return 0;
		}

		memset(color, 0, sizeof color);
		memset(mark, 0, sizeof mark);
		memset(par, 0, sizeof par);

		if (dfs_cycle(rng()%n+1, 0)) {
			cout << 2 << "\n";
			cout << cycle.size() << "\n";
			for (auto u : cycle) cout << u << ' ';
			cout << '\n';
			return 0;
		}
	}

	return 0;
}