#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, k;

vector<int> edges[MAXN];
vector<int> ans;

int state[MAXN];

void impossible() {
	printf("-1\n");
	exit(0);
}

void dfs(int u) {
	if (state[u] == 2) return;
	if (state[u] == 1) impossible();

	state[u] = 1;

	for (int v : edges[u]) dfs(v);

	ans.push_back(u);
	state[u] = 2;
}

int main() {
	scanf("%d%d", &n, &k);
	vector<int> need(k);
	for (int i = 0; i < k; i++) scanf("%d", &need[i]);

	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		while(t--) {
			int j; scanf("%d", &j);
			edges[i].push_back(j);
		}
	}

	for (int i : need) {
		dfs(i);
	}

	printf("%d\n", (int)ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");
}