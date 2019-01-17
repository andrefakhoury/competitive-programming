#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	char ans[n][m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans[i][j] = ".";
	
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < m; j++)
			ans[i][j] = "#";

	bool b = false;
	for (int i = 1; i < n; i += 2) {
		if (b) ans[i][0] = "#";
		else ans[i][m-1] = "#";

		b = !b;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			printf("%c", ans[i][j]);
		printf("\n");
	}

	return 0;
}