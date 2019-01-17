#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, x, qt = 0, soma = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); soma += x;
	}

	while((int)(((float)soma/n)+0.5) < k) {
		qt++; soma += k; n++;
	}

	printf("%d\n", qt);
}