#include <bits/stdc++.h>

using namespace std;

#define MAXN 101
#define MAXM 101

int main() {
	char mapa[MAXN][MAXM];
	int N, M, x, y;
	
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &mapa[i][j]);
			if (mapa[i][j] == 'o') {
				x = i; y = j;
			}
		}
	}
	
	while (1) {
		mapa[x][y] = 'X';
		if (mapa[x+1][y] == 'H') x++;
		else if (mapa[x-1][y] == 'H') x--;
		else if (mapa[x][y+1] == 'H') y++;
		else if (mapa[x][y-1] == 'H') y--;
		else break;
	}

	printf("%d %d\n", x, y);
	return 0;
}	