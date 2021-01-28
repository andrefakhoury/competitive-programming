/** Disjoint Set Union, aka Union Find */
struct DSU {
	int n;
	std::vector<int> par;
	std::vector<int> sz;

	// Union Find with path compression and union by size
	// operations in O(alpha(n)), where alpha is the inverse Ackermann
	DSU(int n) : n(n) {
		par.resize(n + 1);
		sz = std::vector<int>(n + 1, 1);
		iota(par.begin(), par.end(), 0);
	}

	// find leader of current component
	// if necessary, remind to remove the path compression
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}

	// merge two componnets
	// returns whether they dont already belong to the same
	inline bool merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] > sz[v]) std::swap(u, v);
		par[u] = v;
		sz[v] += sz[u];
		return true;
	}
};
