#include <bits/stdc++.h>
using namespace std;

int v[105];

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", v+i);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] <= k) {
			ans++; v[i] = 0;
		} else break;
	}

	for (int i = n-1; i >= 0; i--) {
		if (v[i] && v[i] <= k) {
			ans++; v[i] = 0;
		} else break;
	}

	printf("%d\n", ans);
	return 0;
}