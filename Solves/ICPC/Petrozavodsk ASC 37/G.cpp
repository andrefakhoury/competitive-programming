#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

struct Edge {
	int v, op, n;
	Edge() {}
	Edge(int a, int b, int c = -1) {
		v = a;
		op = b;
		n = c;
	}
};

vector<Edge> edges[MAXN];
int ans[MAXN];
deque<int> q;

void dfs(int u) {
	for (Edge e : edges[u]) {
		if (e.op == 1) {
			q.push_back(e.n);
			dfs(e.v);
			q.pop_back();
		} else {
			ans[u] = q.front();
			q.pop_front();
			dfs(e.v);
			q.push_front(ans[u]);
		}
	}
}

int main() {
	#ifdef ONLINE_JUDGE
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w+", stdout);
	#endif

	int q; scanf("%d", &q);

	vector<int> queries;
	for (int i = 1; i <= q; i++) {
		int op; scanf("%d", &op);

		if (op == 1) {
			int u, x; scanf("%d%d", &u, &x);
			edges[u].push_back(Edge(i, 1, x));
		} else {
			int u; scanf("%d", &u);
			edges[u].push_back(Edge(i, -1));
			queries.push_back(u);
		}
	}

	dfs(0);

	for (int i : queries) printf("%d\n", ans[i]);
}