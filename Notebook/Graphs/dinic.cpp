
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mset(x, y) memset((x), (y), sizeof(x))

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int cap[MAXN][MAXN]; //capacity matrix
int res[MAXN][MAXN]; //residual capacity

int parent[MAXN];	//i got introduced by parent[i]
bool vis[MAXN];

bool BFS()

int dinic(int s, int t, int V) { //O(V*V*E)
	if (s == t) return -1;

	int maxFlow = 0;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			res[i][j] = cap[i][j];

	while(BFS()) {

	}

	return maxFlow;
}