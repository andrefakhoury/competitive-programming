#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

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
		if (a == b) return;
		
		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		siz[b] += siz[a];
	}
};

struct Edge {
	int u, v, w, c;

	bool operator< (Edge& b) const {
		return ((ll)w * c) < ((ll)b.w * b.c);
	}
};

Edge edges[MAXN];

vector<pair<Edge, int> > kruskal(int n, int m) {
	sort(edges+1, edges+m+1);
	UF_union uf;
	uf.init();
	long long cost = 0;
	vector<pair<Edge, int> > ret;

	for (int i = 1; i <= m; i++) {
		Edge e = edges[i];
		if (!uf.same(e.u, e.v)) {
			cost += (ll)e.w * e.c;
			ret.push_back(make_pair(e, i));
			uf.merge(e.u, e.v);
		}
	}

	return ret;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", &edges[i].w);
	for (int i = 1; i <= m; i++) scanf("%d", &edges[i].c);
	for (int i = 1; i <= m; i++) scanf("%d %d", &edges[i].u, &edges[i].v);
	int s; scanf("%d", &s);

	vector<pair<Edge, int> > kkl = kruskal(n, m);

	for (pair<Edge, int> p : kkl) {
		printf("%d\n", p.second);
	}

}