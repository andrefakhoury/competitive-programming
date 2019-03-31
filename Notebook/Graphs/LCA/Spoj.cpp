#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

vector<pii> edges[MAXN];

struct LCA {
	int height[MAXN], st[5 * MAXN], t_in[MAXN];

	bool vis[MAXN];
	vector<int> euler;

	LCA() {
		memset(vis, 0, sizeof vis);
		dfs(1, 1);
		build(1, 0, euler.size() - 1);
	}

	void dfs(int u, int h) {
		vis[u] = true;
		height[u] = h;
		t_in[u] = euler.size();
		euler.pb(u);

		for (pii p : edges[u]) {
			int v = p.first;
			int w = p.second;

			if (!vis[v]) {
				dfs(v, h+1);
				euler.pb(u);
			}
		}
	}

	void build(int p, int lo, int hi) {
		if (lo == hi) st[p] = euler[lo];
		else {
			int mi = (lo + hi)/2;
			build(2*p, lo, mi);
			build(2*p+1, mi+1, hi);
			int l = st[2*p], r = st[2*p+1];
			st[p] = height[l] < height[r] ? l : r;
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

	pii lca(int u, int v) {
		int l = t_in[u], r = t_in[v];
		if (l > r) swap(l, r);
		int p = query(1, 0, euler.size()-1, l, r);

		int mini;
		memset(vis, 0, sizeof vis);
		mini = minimal(p, u);
		memset(vis, 0, sizeof vis);
		mini = min(mini, minimal(p, v));

		return mp(mini, 0);
	}

	int minimal(int ori, int dest) {
		queue<pii> q;
		q.push(mp(ori, INT_MAX));

		int ret = INT_MAX;

		while(true) {



			q.pop();

			for (pii p : edges[a]) {
				int x = p.first;
				int w = p.second;


			}
		}
	}
};

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n-1; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		edges[u].pb(mp(v, w));
		edges[v].pb(mp(u, w));
	}

	LCA lca;

	int q; scanf("%d", &q);
	while(q--) {
		int u, v; scanf("%d%d", &u, &v);
		pii ans = lca.lca(u, v);
		printf("%d %d\n", ans.first, ans.second);
	}
}