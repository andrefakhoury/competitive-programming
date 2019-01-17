#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int qtd = n;
	for (int i = 1; i <= 10000*n; i++) {
		if (i%m == 0) qtd++;
		qtd--;

		if (qtd == 0) return !printf("%d\n", i);	
	}
}