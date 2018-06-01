#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, d, x, qtD = 0, qtX = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &d, &x);

		if (d == 0) {
			if 		(x == 1) qtD++;
			else if (x == 2) qtD++;
			else if (x == 3) qtX++;
			else if (x == 4) qtX++;
		} else if (d == 1) {
			if 		(x == 0) qtX++;
			else if (x == 2) qtD++;
			else if (x == 3) qtD++;
			else if (x == 4) qtX++;
		} else if (d == 2) {
			if 		(x == 0) qtX++;
			else if (x == 1) qtX++;
			else if (x == 3) qtD++;
			else if (x == 4) qtD++;
		} else if (d == 3) {
			if 		(x == 0) qtD++;
			else if (x == 1) qtX++;
			else if (x == 2) qtX++;
			else if (x == 4) qtD++;
		} else if (d == 4) {
			if 		(x == 0) qtD++;
			else if (x == 1) qtD++;
			else if (x == 2) qtX++;
			else if (x == 3) qtX++;
		}
	}

	printf("%s\n", (qtD > qtX) ? "dario" : "xerxes");
	return 0;
}