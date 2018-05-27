int dist[MAXN][MAXN];

for(int k = 1; k <= n; k++) //O(N^3)
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
	        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);