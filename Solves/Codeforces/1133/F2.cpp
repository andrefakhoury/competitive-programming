#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MAXN = 200010;

struct Edge {
	int u, v;
	Edge() {}
	Edge(int x, int y) {
		u = x, v = y;
	}
};

struct UF_union {
	int par[MAXN], siz[MAXN];

	void init() {
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			siz[i] = 1;
		} 
	}

	int find(int x) {
		if (par[x] == x) return x;
		return find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);

		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		siz[b] += siz[a];
	}
};

bool con[MAXN];

int main() {
	int n, m, d; scanf("%d%d%d", &n, &m, &d);
	int deg = 0;
	UF_union uf;
	uf.init();

	queue<Edge> edges, extra;
	vector<Edge> ans;

	while (m--) {
		int u, v; scanf("%d%d", &u, &v);

		if (u == 1 || v == 1) {
			deg++;
			con[u] = con[v] = true;
		} else edges.push(Edge(u, v));
	}


	while (edges.size()) {
		Edge e = edges.front();
		edges.pop();

		if (con[uf.find(e.u)] and con[uf.find(e.v)]) extra.push(e);
		else if (!uf.same(e.u, e.v)) {
			uf.merge(e.u, e.v);
			ans.pb(e);
		}
	}

	while (deg > d and extra.size()) {
		Edge e = extra.front();
		extra.pop();

		if (!uf.same(e.u, e.v)) {
			uf.merge(e.u, e.v);
			ans.pb(Edge(e.u, e.v));
			deg--;
		}
	}

	if (deg == d) {
		for (int i = 2; i <= n; i++) {
			if (con[i] and !uf.same(1, i)) {
				uf.merge(1, i);
				ans.pb(Edge(1, i));
			}
		}
	}

	if (ans.size() == n-1) {
		printf("YES\n");
		for (Edge e : ans) printf("%d %d\n", e.u, e.v);
	} else printf("NO %d\n", ans.size());
	
	return 0;
}