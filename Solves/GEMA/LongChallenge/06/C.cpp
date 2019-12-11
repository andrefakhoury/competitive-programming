#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<pair<int, int>, int> ppi;
typedef long long ll;

struct Edge {
	int u, v, w;

	Edge() {}
	Edge(int a, int b, int c) {
		u = a, v = b, w = c;
	}

	void read() {
		cin >> u >> v >> w;
	}

	bool operator<(Edge const& ed) const {
		return w < ed.w;
	}
};

int par[1005];

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	par[a] = b;
}

bool same(int u, int v) {
	return find(u) == find(v);
}

ll solve(vector<Edge>& edges, int l, int r, int n) {
	for (int i = 1; i <= n; i++) par[i] = i;

	ll ans = 0;
	int ind = lower_bound(edges.begin(), edges.end(), Edge(0, 0, l)) - edges.begin();
	for (int i = ind; edges[i].w <= r; i++) {
		if (same(edges[i].u, edges[i].v)) continue;
		ans += edges[i].w;
		merge(edges[i].u, edges[i].v);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;

	while(T--) {
		int n, m; cin >> n >> m;
		vector<Edge> edges(m);
		for (Edge& e : edges) e.read();
		sort(edges.begin(), edges.end());
		edges.emplace_back(-1, -1, 1e7);
		int q; cin >> q;

		ll ans = 0;
		while(q--) {
			ll l, r; cin >> l >> r;
			l -= ans, r -= ans;
			ans = solve(edges, l, r, n);
			cout << ans << '\n';
		}
	}
}