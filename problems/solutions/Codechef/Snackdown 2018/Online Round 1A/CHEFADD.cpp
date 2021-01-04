#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 100005;

int ppcnt[MAXN];

int main() {
	int t; scanf("%d", &t);

	for (int i = 0; i <= 100000; i++)
		ppcnt[i] = __builtin_popcount(i);
	
	int a, b, c, a1, b1, ans;
	while(t--) {
		ans = 0;
		scanf("%d%d%d", &a, &b, &c);

		a1 = ppcnt[a];
		b1 = ppcnt[b];

		for (int i = 1, j = c-1; i < c; i++, j--) {
			if (ppcnt[i] == a1 && ppcnt[j] == b1)
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}