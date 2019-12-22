#include <stdio.h>

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);

		for (int x = 1; x <= a; x++) {
			for (int y = 1; y <= c-(x*x); y++) {
				for (int z = 1; z <= c-(x*x)-(y*y); z++) {
					if (x + y + z == a &&
						x*y*z == b &&
						x*x + y*y + z*z == c) {
						printf("%d %d %d\n", x, y, z);
						goto LBL;
					}
				}
			}
		}
		
		printf("No solution.\n");

		LBL:
		continue;
	}
}