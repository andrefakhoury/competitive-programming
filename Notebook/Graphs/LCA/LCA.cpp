#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];

struct LCA {
	bool vis[MAXN];
	int height[MAXN], t_in[MAXN], st[4*MAXN];
	vector<int> euler;

	LCA() {
		memset(vis, false, sizeof vis);
		memset(height, 0, sizeof height);
		memset(t_in, 0, sizeof t_in);
		dfs(1, 1);
		build(1, 0, euler.size() - 1);
	}

	void dfs(int u, int h) {
		vis[u] = true;
		height[u] = h;
		t_in[u] = euler.size();
		euler.pb(u);

		for (int v : edges[u]) {
			if (!vis[v]) {
				dfs(v, h+1);
				euler.push_back(u);
			}
		}
	}

	void build(int p, int lo, int hi) {
		if (lo == hi) st[p] = euler[lo];
		else {
			int mi = (lo+hi)/2;
			build(2*p, lo, mi);
			build(2*p+1, mi+1, hi);

			int l = st[2*p], r = st[2*p+1];
			st[p] = (height[l] < height[r]) ? l : r;
		}
	}

	int query(int p, int lo, int hi, int a, int b) {
		if (lo > b or hi < a) return -1;
		if (lo >= a and hi <= b) return st[p];

		int mi = (lo+hi)/2;

		int l = query(2*p, lo, mi, a, b);
		int r = query(2*p+1, mi+1, hi, a, b);

		if (l == -1) return r;
		if (r == -1) return l;

		return height[l] < height[r] ? l : r;
	}

	int lca(int u, int v) {
		int l = t_in[u];
		int r = t_in[v];

		if (l > r) swap(l, r);

		return query(1, 0, euler.size() - 1, l, r);
	}
};

int main() {
	int n, m; n = 7, m = 6;
	pair<int, int> input[] = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {4, 7}};

	for (int i = 0; i < m; i++) {
		int u, v; u = input[i].first, v = input[i].second;
		edges[u].pb(v);
		edges[v].pb(u);
	}

	LCA lca;
	printf("%d\n", lca.lca(1, 2));
	printf("%d\n", lca.lca(5, 6));

	return 0;
}
