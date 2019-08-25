// Tarjan offline version to find LCA
// for sufficiently large m, it's kinda O(1) per query

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

struct UF {
	int pai[MAXN];

	void init(int n) {
		for (int i = 1; i <= n; i++)
			pai[i] = i;
	}

	int find(int x) {
		if (pai[x] == x) return x;
		return pai[x] = find(pai[x]);
	}

	void merge(int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) return;
		pai[a] = b;
	}
};

vector<int> edges[MAXN];
vector<pii> queries[MAXN];
int par[MAXN], ans[MAXN];
bool vis[MAXN];
UF uf;

void dfs(int u) {
	vis[u] = true;
	par[u] = u;

	for (int v : edges[u]) {
		if (!vis[v]) {
			dfs(v);
			uf.merge(u, v);
			par[uf.find(u)] = u;
		}
	}

	for (auto q : queries[u]) {
		if (vis[q.first]) {
			ans[q.second] = par[uf.find(q.first)];
		}
	}
}

// solve SPOJ LCA
int main() {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		uf.init(n);

		vector<bool> isRoot(n+1, true);
		for (int i = 1; i <= n; i++) {
			int k; scanf("%d", &k);
			while(k--) {
				int x; scanf("%d", &x);
				isRoot[x] = false;

				edges[i].push_back(x);
				edges[x].push_back(i);
			}
		}

		int q; scanf("%d", &q);
		for (int i = 1; i <= q; i++) {
			int u, v; scanf("%d%d", &u, &v);
			queries[u].emplace_back(v, i);
			queries[v].emplace_back(u, i);
		}

		int root = -1;
		for (int i = 1; i <= n; i++)
			if (isRoot[i]) root = i;

		dfs(root);

		printf("Case %d:\n", t);
		for (int i = 1; i <= q; i++) {
			printf("%d\n", ans[i]);
		}

		for (int i = 1; i <= n; i++) {
			edges[i].clear();
			queries[i].clear();
			par[i] = 0;
			vis[i] = false;
		}
	}
}