#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int dist[MAXN][MAXN], par[MAXN];
void floydWarshall(int n) {
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	memset(par, -1, sizeof par);

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					par[k] = i;
					par[j] = k;
				}
			}
		}
	}
}

int main() {
	memset(dist, 0x3f, sizeof dist);

	int n, m; cin >> n >> m;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		dist[u][v] = w;
	}

	floydWarshall(n); cout << "\t";
	for (int i = 1; i <= n; i++)
		cout << " 00" << i << "\t";

	for (int i = 1; i <= n; i++) {
		cout << endl << " 00" << i << '\t';
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 0x3f3f3f3f) cout << "INF\t";
			else cout << dist[i][j] << "\t";
		}
	}
	
	cout << endl << "Parents: ";
	for (int u = 1; u <= n; u++)
		cout << u << "->" << par[u] << " ";
	cout << endl;
}