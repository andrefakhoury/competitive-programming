#include <bits/stdc++.h>
using namespace std;

#define GREEN 0
#define BLACK 1

#define int long long

int32_t main() {
	int n, k, g, b; scanf("%lld%lld%lld%lld", &n, &k, &g, &b);

	int A = g, B = b;
	char c1 = 'G', c2 = 'B';

	if (A < B) {
		swap(A, B);
		swap(c1, c2);
	}

	if (A > (B+1)*k) return !printf("NO\n");

	if (A == B) {
		for (int i = 0; i < A; i++) printf("GB");
		return !printf("\n");
	}

	int available = A - (B + 1);
	for (int i = 0; i <= B; i++) {
		printf("%c", c1);
		int cur = min(k-1, available);
		available -= cur;
		for (int j = 1; j <= cur; j++) printf("%c", c1);
		if (i != B) printf("%c", c2);
	}

	return !printf("\n");
}