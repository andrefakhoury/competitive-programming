#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; scanf("%d", &q);
	while(q--) {
		int l1, r1, l2, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

		int x = rand()%(r1 - l1) + l1;

		int y = x;
		while (y == x)
			y = (x == l2 ? r2 : (x == r2 ? l2 : rand()%(r2 - l2) + l2));

		printf("%d %d\n", x, y);
	}
	return 0;
}