#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

int n, m;

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

struct Edge {
	int u, v;
	double w;

	Edge() {}
	Edge(int x, int y, double z) {
		u = x, v = y, w = z;
	}

	bool operator<(Edge const& other) {
		return w < other.w;
	}
};

vector<Edge> edges;
vector<Edge> result;

int kruskal() {
	result.clear();
	int cost = 0;

	UF_union uf;
	uf.init();

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
		if (!uf.same(e.u, e.v)) {
			result.push_back(e);
			uf.merge(e.u, e.v);
			cost += e.w;
		}
	}

	return cost;
}

int main() {

	while (scanf("%d%d", &n, &m), n || m) {
		edges.clear();
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			edges.emplace_back(u, v, w);
			edges.emplace_back(v, u, w);

			sum += w;
		}
		printf("%d\n", sum - kruskal());
	}
}