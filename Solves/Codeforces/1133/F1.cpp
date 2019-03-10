#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
const int MAXN = 200010;

vector<int> edges[MAXN];
int n, m;
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = true;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int v : edges[u]) {
			if (!vis[v]) {
				printf("%d %d\n", u, v);
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	int num = 0, id = -1;
	for (int i = 1; i <= n; i++) {
		if (num < edges[i].size()) {
			num = edges[i].size();
			id = i;
		}
	}

	bfs(id);
}