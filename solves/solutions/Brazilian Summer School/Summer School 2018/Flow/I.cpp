#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f;
const int MAXN = 60;

struct Dinic {
	const long long flow_inf = 1e18;
	
	struct FlowEdge {
		int v, u;
		long long cap, flow = 0;
		FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
		void print() {
			printf("%d to %d: cap %lld and flow %lld\n", v, u, cap, flow);
		}
	};

	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic() {
		adj.resize(8000);
		level.resize(8000);
		ptr.resize(8000);
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

	long long flow(int src, int snk) {
		this->s = src, this->t = snk;
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

char mat[MAXN][MAXN];
int op[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m; 

int get(int i, int j) {
	return (i - 1) * m + j;
}

bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

bool vis[MAXN][MAXN];

void flood(int i, int j) {
	if (!valid(i, j)) return;
	if (vis[i][j]) return;
	vis[i][j] = true;

	if (mat[i][j] == '.') return;
	for (int k = 0; k < 4; k++)
		flood(i+op[k][0], j+op[k][1]);
}

bool conexo() {
	return true;

	bool flag = true;
	for (int i = 1; flag && i <= n; i++) {
		for (int j = 1; flag && j <= m; j++) {
			if (mat[i][j] != '.') {
				flood(i, j);
				flag = false;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] != '.' && !vis[i][j]) return false;
		}
	}

	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	int SRC = n * m + 1, SNK = n * m + 2;

	map<char, int> valc;
	valc['H'] = 1;
	valc['O'] = 2;
	valc['N'] = 3;
	valc['C'] = 4;

	Dinic f;
	ll sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &mat[i][j]);
			sum += valc[mat[i][j]];
		}
	}

	int N = m * n + 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '.') continue;

			int u = get(i, j), auxU = u + N;

			if ((i+j)%2) {
				f.add_edge(u, SNK, valc[mat[i][j]]);
				continue;
			}

			f.add_edge(SRC, u, INF);
			f.add_edge(u, auxU, valc[mat[i][j]]);

			for (int k = 0; k < 4; k++) {
				int I = i + op[k][0], J = j + op[k][1];
				if (!valid(I, J) || mat[I][J] == '.') continue;
				int v = get(I, J);
				f.add_edge(auxU, v, 1);
			}
		}
	}

	printf("%s\n", conexo() && sum && (2 * f.flow(SRC, SNK) == sum) ? "Valid" : "Invalid");
}