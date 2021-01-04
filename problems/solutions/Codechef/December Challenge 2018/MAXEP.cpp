#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150001;
int memo[MAXN];

int chute(int low, int high) {
	if (low == high) return low;

	int broken;
	for (int i = low; i <= high; i += rand()%(high-i)+1) {

		if (memo[i] != -1) broken = memo[i];
		else {
			printf("1 %d\n", i); fflush(stdout);
			scanf("%d", &broken);
			memo[i] = broken;
		}


		if (broken == 0) {
			low = i+1;
			continue;
		} else if (broken == 1) {
			printf("2\n"); fflush(stdout);
			return chute(low, i);

		} else if (broken == -1) {
			return rand()%(high-low+1)+low;
		}
	}

	if (low == high) return low;
	return chute(low, high);
}

int seila(int n) {
	int l = 1, r = n, m, x;
	while(l < r) {
		m = (l*9 + r)/10;
		printf("1 %d\n", m); fflush(stdout);
		scanf("%d", &x);
		if (x == 0) {
			l = m+1;
		} else if (x == 1) {
			printf("2\n");
			r = m;
		} else {
			return rand()%(r-l+1)+l;
		}
	}
	return r;
}

int main() {
	srand(time(NULL));
	memset(memo, -1, sizeof memo);
	int n, c; scanf("%d%d", &n, &c);

	int ans;
	// if (n <= 1000) ans = seila(n);
	// else ans = chute(1, n);
	ans = seila(n);
	printf("3 %d\n", ans);

	return 0;
}