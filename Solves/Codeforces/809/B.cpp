#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	printf("1 %d %d\n", x, y); fflush(stdout);
	char inp[5]; scanf(" %s", inp);
	return !strcmp(inp, "TAK");
}

int get(int l, int r) {
	if (l > r) return -1;

	while (l < r) {
		int m = (l+r)/2;
		if (query(m, m+1)) r = m;
		else l = m+1;
	}

	return l;
}

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int x = get(1, n);
	int y = get(1, x-1);
	if (y == -1 || !query(y, x)) y = get(x+1, n);

	printf("2 %d %d\n", x, y); fflush(stdout);
	return 0;
}