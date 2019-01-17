#include <stdio.h>

int main() {
	int x;
	bool y = false;
	scanf("%d", &x);
	
	if (x%2 != 0 || x==2) y = false;
	else y = true;
	
	if (y) printf("YES\n");
	else printf("NO\n");
	return 0;
}
