#include <bits/stdc++.h>
using namespace std;

#define MAXN 120005
#define pb push_back

int main() {
	int n, ans = 0, curAns = 0, last = -1, x;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		if (x >= last) curAns++;
		else curAns = 1;
		last = x;
		ans = max(ans, curAns);
	} printf("%d\n", ans);
	return 0;
}