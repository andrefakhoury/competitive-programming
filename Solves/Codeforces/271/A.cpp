#include <stdio.h>
int solve(int n) {
	if (n/1000 != n/100%10 && n/1000 != n/10%10 && n/1000 != n%10 && n/100%10 != n/10%10 && n/100%10 != n%10 && n/10%10 != n%10) return 1;
	return 0;
}
int main () {
	int n; scanf("%d", &n);
	while (!solve(++n));
	return !printf("%d\n", n);
}