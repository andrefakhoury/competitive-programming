#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1e5, m = 1e5;
	printf("%d %d\n", n, m);

	for (int i = 1; i <= n; i++) printf("%c", rand()%26 + 'a');
	printf("\n");

	while(m--) {
		int u = rand()%n + 1;
		int v = rand()%n + 1;

		printf("%d %d\n", u, v);
	}

	printf("1 293\n");
}