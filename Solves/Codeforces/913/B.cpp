#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

vector<int> edges[MAXN];

int dfs(int u) {
	if (edges[u].size() == 0) return 1;

	int leaf = 0;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		leaf += dfs(v);
	}

	if (leaf < 3) {
		printf("No\n");
		exit(0);
	}

	return 0;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n-1; i++) {
		int x; scanf("%d", &x);
		edges[x].push_back(i+1);
	}

	dfs(1);
	printf("Yes\n");

	return 0;
}