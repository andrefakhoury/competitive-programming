#include <bits/stdc++.h>
using namespace std;

struct Tree {
	const int LOG = 21;

	int n;
	vector<vector<int>> edges;
	vector<vector<int>> parent;
	vector<int> level;

	Tree(int n) : n(n), edges(n), level(n) {}

	void add_edge(int u, int v) {
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	void init_lca(int root = 0) {
		parent.assign(n, vector<int>(LOG));
		fill(level.begin(), level.end(), 0);
		auto dfs_lca = [&](auto&& dfs_lca, int u, int p)->void {
			parent[u][0] = p;
			for (int v : edges[u]) if (v != p) {
				level[v] = level[u] + 1;
				dfs_lca(dfs_lca, v, u);
			}
		};
		dfs_lca(dfs_lca, root, root);
		for (int b = 1; b < LOG; b++)
			for (int u = 0; u < n; u++)
				parent[u][b] = parent[parent[u][b-1]][b-1];
	}

	int lca(int u, int v) {
		if (level[u] < level[v]) swap(u, v);
		for (int b = LOG-1; b >= 0; b--)
			if (level[u] - (1 << b) >= level[v])
				u = parent[u][b];
		if (u == v) return u;
		for (int b = LOG-1; b >= 0; b--)
			if (parent[u][b] != parent[v][b])
				u = parent[u][b], v = parent[v][b];
		return parent[u][0];
	}
};

int main() {
	int n = 10;
	Tree g(n);
	for (int i = 1; i < n; i++) g.add_edge(i-1, i);
	g.init_lca();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d, %d: %d\n", i, j, g.lca(i, j));
		}
	}


}