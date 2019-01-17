#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);

	if (n%2 == 0) return !printf("-1\n");
	for (int i = 0; i < n; i++) printf("%d ", i); printf("\n");
	for (int i = 0; i < n; i++) printf("%d ", i); printf("\n");
	for (int i = 0; i < n; i++) printf("%d ", (i+i)%n); printf("\n");
}