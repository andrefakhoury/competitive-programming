#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 105, MAXC = 1000;

vector<int> X[MAXC], Y[MAXC];
map<int, pair<int, int> > points;

vector<int> edges[MAXN];
bool vis[MAXN];

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < edges[u].size(); i++) {
		int v = edges[u][i];
		if (!vis[v]) dfs(v);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[x].pb(i);
		Y[y].pb(i);
		points[i] = make_pair(x, y);
	}


	int id1, id2;
	for (int coord = 1; coord < MAXC; coord++) {
		for (int i = 0; i < X[coord].size(); i++) {
			for (int j = i+1; j < X[coord].size(); j++) {
				id1 = X[coord][i];
				id2 = X[coord][j];
				edges[id1].push_back(id2);
				edges[id2].push_back(id1);
			}
		}
	}
	for (int coord = 1; coord < MAXC; coord++) {
		for (int i = 0; i < Y[coord].size(); i++) {
			for (int j = i+1; j < Y[coord].size(); j++) {
				id1 = Y[coord][i];
				id2 = Y[coord][j];
				edges[id1].push_back(id2);
				edges[id2].push_back(id1);
			}
		}
	}

	int ans = 0;
	dfs(1);

	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			ans++;
			dfs(i);
		}
	}

	return !printf("%d\n", ans);
}