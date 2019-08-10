#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];

void unsort(int l, int r) {
	if (l >= r) return;
	if (k <= 0) return;

	int m = (l + r) / 2;
	unsort(m+1, r);

	if (a[m+1] > a[m] && k > 0) {
		swap(a[m], a[m+1]);
		k--;
	}
	unsort(l, m);

}

int main() {
	scanf("%d%d", &n, &k);

	if (k%2 == 0) return !printf("-1\n");
	k--;
	for (int i = 1; i <= n; i++) a[i-1] = i;

	unsort(0, n-1);

	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i-1]);
	} printf("\n");
}