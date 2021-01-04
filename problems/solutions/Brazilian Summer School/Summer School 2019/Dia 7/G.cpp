#include <bits/stdc++.h>
using namespace std;

int grundy(int n, int k) {
	// se k for par, as torres sempre vao se anular
	if (k%2 == 0) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		return n % 2 ^ 1;
	} else { //senao, as k-1 torres vao se anular
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 0;
		if (n == 3) return 1;
		if (n == 4) return 2;

		if (n%2) return 0;
		return grundy(n/2, k) == 1 ? 2 : 1;
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		sum ^= grundy(x, k);
	}

	printf("%s\n", sum == 0 ? "Nicky" : "Kevin");
}