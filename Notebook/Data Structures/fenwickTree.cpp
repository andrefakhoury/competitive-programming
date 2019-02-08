#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int BIT[MAXN];

void update(int i, int val) {
	while (i < MAXN) {
		BIT[i] += val;
		i += i&-i;
	}
}

int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += BIT[i];
		i -= i&-i;
	}
	return ret;
}

int rangeSum(int i, int j) {
	return sum(j) - sum(i-1);
}

int main() {
	int q; scanf("%d", &q);
	while(q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int i, x; scanf("%d%d", &i, &x);
			update(i, x);
		} else {
			int i, j; scanf("%d%d", &i, &j);
			printf("%d\n", rangeSum(i, j));
		}
	}
}
