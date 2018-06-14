#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MAXN 1000
#define mp pake_pair

int dist[MAXN];
vector<pair<int, int> > edges[MAXN];

void dijkstra(int s) {

}

int main() {
	int n, m, c, k, x, y, w;
	while(scanf("%d%d%d%d", &n, &m, &c, &k), n && m && c && k) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &x, &y, &w);
			edges[x].pb(mp(y, w));
		}
	}

	return 0;
}