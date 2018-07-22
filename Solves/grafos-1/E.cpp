#include <bits/stdc++.h>
using namespace std;

#define mset(x, y) memset(x, y, sizeof x)
#define MAXN 1005
#define pb push_back

int adj[MAXN][MAXN];
vector<int> edges[MAXN];
int dist[MAXN];

void bfs(int s) {
	mset(dist, -1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)edges[u].size(); i++) {
			if (dist[edges[u][i]] == -1) {
				q.push(edges[u][i]);
				dist[edges[u][i]] = dist[u]+1;
			}
		}
	}

}

int main() {
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
			if (adj[i][j] == 1) {
				edges[i].pb(j);
				edges[j].pb(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int j = 1; j <= n; j++) {
			if (dist[j] != adj[i][j]) return !printf("nao\n");
		}
	}
	printf("sim\n");
	return 0;
}
