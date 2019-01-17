#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500100;

bool valid(int k) {
	return k > 0 && k < MAXN;
}

int dist[MAXN];
int bfs(int ini, int obj) {
	dist[ini] = 0;

	queue<int> q;
	q.push(ini);
	
	int u;
	while(q.size()) {
		u = q.front();
		q.pop();

		if (u == obj) break;

		int op1 = u * 2;
		int op2 = u - 1;

		if (valid(op1) && dist[op1] == -1) {
			q.push(op1);
			dist[op1] = dist[u] + 1;
		}

		if (valid(op2) && dist[op2] == -1) {
			q.push(op2);
			dist[op2] = dist[u] + 1;
		}
	}

	return dist[u];
}

int main() {
	memset(dist, -1, sizeof dist);
	int n, m; scanf("%d%d", &n, &m);
	return !printf("%d\n", bfs(n, m));
}