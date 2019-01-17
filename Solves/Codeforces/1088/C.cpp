#include <bits/stdc++.h>
using namespace std;

int opposite(int x, int mod) {
	return mod-(x%mod);
}

int main() {
	int n; scanf("%d", &n);

	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	printf("%d\n", n+1);
	
	int carry = 0, qtt;
	for (int i = n; i >= 1; i--) {
		a[i] = (a[i] + carry)%(n+1);

		qtt = (opposite(a[i], n+1) + i)%(n+1);
		carry = (carry + qtt)%(n+1);

		printf("1 %d %d\n", i, qtt);
	}

	printf("2 %d %d\n", n, n+1);

	return 0;
}
