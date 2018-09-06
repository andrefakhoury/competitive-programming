dp[i][j] = {edge i-> se tiver, infinito se nao}

for (k: 1, n)
	for (i: 1, n)
		for (j: 1, n)
			dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);


for (k: 1, n)
	for (i: 1, n)
		for (j: 1, n)
			dp[i][j] = min(dp[i][j], max(dp[i][k],dp[k][j]));

