#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int u, vector<bool>& vis, vector<vector<int> >& edges, vector<int>& ans) {
	if (vis[u]) return;
	vis[u] = true;
		
	for (int v : edges[u]) {
		if (!vis[v]) dfs(v, vis, edges, ans);
	}

	ans.push_back(u);
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m), n || m) {
		vector<vector<int> > edges(n+10);
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			edges[u].push_back(v);
		}

		vector<int> ans;
		vector<bool> vis(n+10, false);

		for (int u = 1; u <= n; u++) {
			if (!vis[u]) dfs(u, vis, edges, ans);
		}

		reverse(ans.begin(), ans.end());

		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d", ans[i]);
			if (i != (int)ans.size() - 1)
				printf(" ");

		}

		printf("\n");
	}
}