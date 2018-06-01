#include <bits/stdc++.h>

using namespace std;

#define MAXN 100002

int num[MAXN];

int main() {
	int N, x, last = 1000000, ind = 0, ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		
		if (abs(last-x) <= 1) {
			num[ind]++;
		} else {
			ind++;
			num[ind]++;
		}
		last = x;
		ans = max(ans, num[ind]);
	}

	printf("%d\n", ans);
}