#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

int n, X;

int main() {
	int x, menor = INF, maior = 0; scanf("%d%d", &n, &X);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		menor = min(menor, x);
		maior = max(maior, x);
		if (x == X) return !printf("1\n");
	}
	if (menor > X || maior < X) return !printf("-1\n");

	return !printf("2\n");
}