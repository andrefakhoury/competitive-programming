#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 5;

struct FlowEdge {
	int v, u;
	long long cap, flow = 0;
	FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
	const long long flow_inf = 1e18;

	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int v, int u, long long cap) {
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	long long dfs(int v, long long pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	long long flow() {
		long long f = 0;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

int n, k;
int op[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int get(int x, int y) {
	return x*n + y;
}

void teg(int u, int& i, int& j) {
	i = u/n + 1;
	j = u%n + 1;
}

bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

int main() {
	scanf("%d%d", &n, &k);

	set<int> st;
	for (int i = 0; i < k; i++) {
		int x, y; scanf("%d%d", &x, &y);
		st.emplace(get(x-1, y-1));
	}

	k = st.size();

	int N = n*n, qtt = N - k, cap = qtt/2;
	if (qtt%2) return !printf("No\n");

	int s = n*n, auxS = n*n+1, t = n*n+2, auxT = n*n+3;
	Dinic f(n*n+4, s, t);

	f.add_edge(s, auxS, cap);
	f.add_edge(auxT, t, cap);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (st.count(get(i, j))) continue;
			int u = get(i, j);

			if ((i+j)%2) {
				f.add_edge(u, auxT, 1);
				continue;
			}

			f.add_edge(auxS, u, 1);
			for (int pp = 0; pp < 4; pp++) {
				int I = i + op[pp][0], J = j + op[pp][1];
				int v = get(I, J);
				if (!valid(I, J) || st.count(v)) continue;
				f.add_edge(u, v, 1);
			}
		}
	}

	if (f.flow() != cap) return !printf("No\n");
	printf("Yes\n");

	set<pii> H, V;
	for (FlowEdge ed : f.edges) {
		if (ed.v == s || ed.v == auxS || ed.v == t || ed.v == auxT) continue;
		if (ed.u == s || ed.u == auxS || ed.u == t || ed.u == auxT) continue;
		if (!ed.flow) continue;

		int i1, j1, i2, j2;
		teg(ed.v, i1, j1);
		teg(ed.u, i2, j2);

		if (i1 == i2) {
			if (j1 < j2) V.emplace(i1, j1);
			else V.emplace(i2, j2);
		} else {
			if (i1 < i2) H.emplace(i1, j1);
			else H.emplace(i2, j2);
		}
	}

	printf("%ld\n", H.size());
	for (auto p : H) printf("%d %d\n", p.fi, p.se);
	printf("%ld\n", V.size());
	for (auto p : V) printf("%d %d\n", p.fi, p.se);

	return 0;
}