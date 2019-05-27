#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int t_in[MAXN], low[MAXN];

vector<int> scc[MAXN];
stack<int> tarj;

int curTime = 1, curColor = 1;

void dfs(int u) {
	t_in[u] = curTime++;
	low[u] = t_in[u];
	tarj.push(u);

	for (int v : edges[u])
		if (!t_in[v]) dfs(v);

	for (int v : edges[u])
		low[u] = min(low[u], t_in[v]);

	if (low[u] == t_in[u]) {
		while(tarj.size()) {
			int v = tarj.top();
			tarj.pop();
			scc[curColor].push_back(v);

			if (v == u) break;

		}

		curColor++;
	}
}

void tarjan(int n) {
	for (int i = 1; i <= n; i++)
		if (!t_in[i]) dfs(i);

	for (int i = 1; i < curColor; i++) {
		for (int v : scc[i]) printf("%d ", v);
		printf("\n");
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
	}

	tarjan(n);
}
