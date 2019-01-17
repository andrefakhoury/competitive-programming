#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 100005;

vector<int> edges[MAXN];
int color[MAXN];

void impossible() {
	exit(!printf("-1\n"));
}

int outra(int a) {
	return a == 1 ? 2 : 1;
}

int bfs(int s) {
	queue<int> q;
	q.push(s);
	color[s] = 1;

	int sum[3] = {0, 1, 0};

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (auto v : edges[u]) {
			if (color[v] == color[u]) impossible();

			if (color[v] == 0) {
				color[v] = outra(color[u]);
				sum[color[v]]++;
				q.push(v);
			}
		}
	}

	return max(sum[1], sum[2]);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i]) continue;

		int cur = bfs(i);
		ans += cur;
	}

	printf("%d\n", ans);
}