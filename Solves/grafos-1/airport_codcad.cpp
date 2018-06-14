#include <bits/stdc++.h>

using namespace std;

#define MAXN 101
#define MAXM 10000
#define pb push_back

int air[MAXN];

int main() {
	int a, v, x, y, teste = 1;
	while(scanf("%d %d", &a, &v), a && v) {
		memset(air, 0, sizeof(air));

		for (int i = 0; i < v; i++) {
			scanf("%d %d", &x, &y);
			air[x]++;
			air[y]++;
		}

		int maxi = -1;
		for (int i = 0; i < MAXN-1; i++) {
			maxi = max(maxi, air[i]);
		}

		printf("Teste %d\n", teste);
		for (int i = 0; i < MAXN; i++) {
			if (air[i] == maxi) printf("%d ", i);
		}

		printf("\n");
		teste++;
	}


	return 0;
}