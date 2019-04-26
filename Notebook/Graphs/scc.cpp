#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> edges[MAXN];
vector<int> invrs[MAXN];

vector<int> sameColor[MAXN];
int color[MAXN];

vector<int> order;
bool vis[MAXN];

void dfsOrder(int u) {
	vis[u] = true;

	for (int v : edges[u])
		if (!vis[v]) dfsOrder(v);

	order.push_back(u);
}

void dfsColor(int u, int curColor) {
	color[u] = curColor;
	sameColor[curColor].push_back(u);

	for (int v : invrs[u])
		if (!color[v]) dfsColor(v, curColor);
}

void css(int n) {
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfsOrder(i);

	reverse(order.begin(), order.end());

	int curColor = 0;
	for (int u : order)
		if (!color[u]) dfsColor(u, ++curColor);

	for (int c = 1; c <= curColor; c++) {
		printf("%d: ", c);
		for (int u : sameColor[c])
			printf("%d ", u);
		printf("\n");
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		invrs[v].push_back(u);
	}

	css(n);
}