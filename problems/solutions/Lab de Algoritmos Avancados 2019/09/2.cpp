#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define pb push_back
const int MAXN = 300;

int color[MAXN];

bool dfs(int u, int c, vector<vector<int> >& edges) {
	if (color[u] && color[u] != c) return false;
	if (color[u]) return true;

	color[u] = c;
	for (int v : edges[u])
		if (!dfs(v, 3 - c, edges)) return false;

	return true;
}


int main() {

	int n, m;
	while (scanf("%d%d", &n, &m) > 1 && n != 0) {
		vector<vector<int> > edges(n + 1);
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			edges[u].pb(v);
			edges[v].pb(u);
		}

		memset(color, 0, sizeof color);
		bool ans = true;

		for (int i = 1; i <= n; i++) {
			if (!color[i])
				ans = ans && dfs(i, 1, edges);
		}

		printf("%s.\n", ans ? "BICOLORABLE" : "NOT BICOLORABLE");
	}
}