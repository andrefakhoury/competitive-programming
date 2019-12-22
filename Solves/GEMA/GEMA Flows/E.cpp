#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 4e6;
const double EPS = 1e-7;
const long long flow_inf = 1e18;

struct Dinic {
	
	struct FlowEdge {
		int v, u;
		long long cap, flow;
		FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {
			flow = 0;
		}
	};

	vector<FlowEdge> edges;
	vector<vector<int> > adj;
	int n, m;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
		m = 0;
	}

	inline void add_edge(int v, int u, long long cap) {
		edges.pb(FlowEdge(v, u, cap));
		edges.pb(FlowEdge(u, v, 0));
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	inline bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int K = 0; K < adj[v].size(); K++) {
				int id = adj[v][K];
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

	inline long long flow() {
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

struct Point {
	long long x, y;

	Point() {}
};

struct Input {
	Point p;
	int qtt, cap;

	Input() {}

	inline void read() {
		scanf("%lld %lld %d %d", &p.x, &p.y, &qtt, &cap);
	}
};

inline bool canJump(Point& a, Point& b, double dist) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+EPS <= dist;
}

inline void _solve() {
	int n, total = 0;
	double d;
	scanf("%d%lf", &n, &d);
	vector<Input> vec(n);

	int SRC = 2*n;
	Dinic f(2*n+1, SRC, 0);

	for (int i = 0; i < n; i++) {
		vec[i].read();

		f.add_edge(i, i+n, vec[i].cap);
		f.add_edge(SRC, i, vec[i].qtt);
		total += vec[i].qtt;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (canJump(vec[i].p, vec[j].p, d*d)) {
				f.add_edge(i+n, j, INF);
				f.add_edge(j+n, i, INF);
			}
		}
	}

	Dinic bkp = f;

	vector<int> ans;
	for (int SNK = 0; SNK < n; SNK++) {

		f = bkp;
		f.t = SNK;
		int flow = f.flow();

		if (flow == total) ans.pb(SNK);
	}

	if (ans.empty()) printf("-1\n");
	else {
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		printf("\n");
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) _solve();

	return 0;
}