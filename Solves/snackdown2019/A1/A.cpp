#include <bits/stdc++.h>
using namespace std;

bool cmp (int& a, int& b) {
	return a > b;
}

int main() {
	int t; scanf("%d", &t);
	int n, k, s[100005], ans;

	while(t--) {
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", s+i);

		sort(s+1, s+n+1, cmp);
		for (int i = 1; i <= n; i++) if (s[i] >= s[k]) ans++;

		printf("%d\n", ans);
	}
	return 0;
}