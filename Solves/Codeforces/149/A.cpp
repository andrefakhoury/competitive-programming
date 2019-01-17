#include <bits/stdc++.h>
using namespace std;

int a[20], k;
int solve(int at, int cur) {
	if (cur >= k) return 0;
	if (at > 12) return 0x3f3f3f;

	return min(1 + solve(at+1, cur+a[at]), solve(at+1, cur));
}

int main() {
	scanf("%d", &k);
	for (int i = 1; i <= 12; i++) scanf("%d", a+i);

	int ans = solve(1, 0);
	ans = ans > 12 ? -1 : ans;

	printf("%d\n", ans);
}