#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;
int a[MAXN];

void solve(int n) {
	int x, y, z;
	printf("1 1 2 3\n"); fflush(stdout);
	scanf("%d", &x);
	printf("1 1 3 4\n"); fflush(stdout);
	scanf("%d", &y);
	printf("1 1 2 4\n"); fflush(stdout);
	scanf("%d", &z);

	a[1] = x xor y xor z;
	for (int i = 2; i <= n; i++) a[i] = a[i-1]+1;
}



int main() {
	int t, n; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);

		solve(n);

		// for (int i = 1; i <= n; i++) {
		// 	printf("1 %d %d %d\n", i, i, i); fflush(stdout);
		// 	scanf("%d", a+i);
		// }

		printf("2 ");
		for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		printf("\n"); fflush(stdout);

		int x; scanf("%d", &x);
		if (x == -1) return 0;
	}
}