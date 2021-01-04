#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef pair<int, int> pii;

const int MAXN = 505;

int adj[MAXN][MAXN], deg[MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u][v] = adj[v][u] = 1;
		deg[u]++, deg[v]++;
	}

	int ans = 1e5;
	for (int k = 1000; k >= 0; k--) {
		bool used = false;
		for (int u = 1; u <= n; u++) {
			for (int v = u+1; v <= n; v++) {
				if (!adj[u][v] && deg[u] + deg[v] >= k) {
					deg[u]++, deg[v]++;
					adj[u][v] = adj[v][u] = 1;
					used = true;
					ans = k;
				}
			}
		}

		k += used;
	}

	printf("%d\n", ans);
}