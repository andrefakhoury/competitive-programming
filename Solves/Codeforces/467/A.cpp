#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int a, b, ans = 0;
	while(n--) {
		scanf("%d%d", &a, &b);
		if (b-a >= 2) ans++;
	}
	return !printf("%d\n", ans);
}