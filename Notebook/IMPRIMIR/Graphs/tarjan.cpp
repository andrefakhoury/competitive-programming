#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int tin[MAXN], low[MAXN];
vector<int> scc[MAXN];
stack<int> tarj;
bool stackMember[MAXN];

int curTime = 0, curColor = 0;

void dfs(int u) {
	tin[u] = low[u] = ++curTime;
	tarj.push(u);
	stackMember[u] = true;

	for (int v : edges[u]) {
		if (!tin[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (stackMember[v] == true)
			low[u] = min(low[u], tin[v]);
	}

	int w = 0;
	if (low[u] == tin[u]) {
		curColor++;

		while (tarj.top() != u) {
			w = tarj.top();
			scc[curColor].push_back(w);
			stackMember[w] = false;
			tarj.pop();
		}

		w = (int) tarj.top();
		scc[curColor].push_back(w);
		stackMember[w] = false;
		tarj.pop();
	}
}

void tarjan(int n) {
	for (int i = 1; i <= n; i++) {
		if (!tin[i]) dfs(i);
	}

	printf("%d\n", curColor);
	for (int i = 1; i <= curColor; i++) {
		printf("%ld\n", scc[i].size());
		for (int u : scc[i])
			printf("%d ", u);
		printf("\n");
	}
} 

int main() {
	int n; scanf("%d", &n);

	int u, v;
	while(~scanf("%d%d", &u, &v)) {
		edges[u].push_back(v);
	}

	tarjan(n);
}