#include <bits/stdc++.h>
using namespace std;

struct Graph {
	struct Edge {
		int to;
		long long weight;
		Edge() : to(), weight() {}
		Edge(int to, long long weight) : to(to), weight(weight) {}
		Edge change(int new_to) { return Edge(new_to, weight); }
		bool operator<(Edge const& ed) const { return make_pair(to, weight) < make_pair(ed.to, ed.weight); }
	};

	int n;
	vector<vector<Edge>> edges;
	vector<vector<Edge>> rev_edges;

	Graph(int n) : n(n), edges(n), rev_edges(n) {}

	void add_edge(int from, Edge to) {
		edges[from].push_back(to);
		rev_edges[to.to].push_back(to.change(from));
	}

	vector<int> toposort(bool ignore_impossible = false) {
		vector<int> vis(n), order;

		auto dfs_order = [&](auto&& dfs_order, int u)->bool {
			vis[u] = 1;
			for (Edge ed : edges[u]) {
				if (vis[ed.to] == 1 && !ignore_impossible) return false;
				else if (vis[ed.to] == 2) dfs_order(dfs_order, ed.to);
			}
			vis[u] = 2;
			order.push_back(u);
			return true;
		};
		for (int i = 0; i < n; i++) if (!vis[i]) {
			if (!dfs_order(dfs_order, i))
				return {}; // impossible toposort
		}
		reverse(order.begin(), order.end());
		return order;
	}

	vector<int> kosaraju() {
		vector<int> order = toposort(true);
		vector<int> color(n, -1);
		int cur_color = 0;

		auto dfs_color = [&](auto&& dfs_color, int u, int c)->void {
			color[u] = c;
			for (Edge ed : rev_edges[u]) if (color[ed.to] == -1)
				dfs_color(dfs_color, ed.to, c);
		};

		for (int u : order) if (color[u] == -1)
			dfs_color(dfs_color, u, cur_color++);

		return color;
	}

	vector<vector<Edge>> get_scc_dag() {
		vector<int> color = kosaraju();
		
		int n_dag = *max_element(color.begin(), color.end());
		vector<vector<Edge>> scc_edges(n_dag);

		for (int u = 0; u < n; u++) {
			for (Edge ed : edges[u]) {
				scc_edges[color[u]].push_back(ed.change(color[ed.to]));
			}
		}

		return scc_edges;
	}

	vector<long long> dist_bfs(int from) {
		vector<int> qu = {from};
		vector<long long> dist(n, -1);
		for (int i = 0; i < (int) qu.size(); i++) {
			for (Edge ed : edges[qu[i]]) if (dist[ed.to] == -1) {
				qu.push_back(ed.to);
				dist[ed.to] = dist[qu[i]] + 1;
			}
		}
		return dist;
	}

	vector<long long> dist_dijkstra(int from) {
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.emplace(0, from);

		vector<long long> dist(n, 1e17);
		dist[from] = 0;

		while(pq.size()) {
			long long cur_d = pq.top().first;
			int u = pq.top().second;
			pq.pop();

			if (cur_d > dist[u]) continue;

			for (Edge ed : edges[u]) if (dist[ed.to] > dist[u] + ed.weight) {
				dist[ed.to] = dist[u] + ed.weight;
				pq.emplace(dist[ed.to], ed.to);
			}
		}

		return dist;
	}
};

int main() {
	
}