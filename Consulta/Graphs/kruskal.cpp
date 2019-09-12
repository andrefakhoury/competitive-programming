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

double kruskal() {
	result.clear();
	double cost = 0;

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