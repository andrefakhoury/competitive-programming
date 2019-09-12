// algorithm to find bridges and cut (articulation) vertex

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
int tin[MAXN], low[MAXN], curTime;
bool vis[MAXN];

int dfs(int u, int p = -1) {
	vis[u] = true;
	tin[u] = low[u] = ++curTime;

	bool any = false;
	int numChild = 0;

	for (int v : edges[u]) {
		if (v == p) continue;
		if (!vis[v]) {
			dfs(v, u);
			numChild++;
			if (low[v] >= tin[u]) any = true;
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) { // (u, v) is bridge
				printf("(%d,%d) is bridge!\n", u, v);
			}
		} else low[u] = min(low[u], tin[v]);
	}

	if (p == -1 && numChild >= 2) { // articulation
		printf("%d is articulation vertex!\n", u);
	} else if (p != -1 && any) { // articulation
		printf("%d is articulation vertex!\n", u);		
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
}