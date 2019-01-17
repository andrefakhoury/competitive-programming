#include <stdio.h>

int main() {
	int n;
	
	scanf("%d", &n);
	int x[n];
	int fase;
	int a;
	
	for (a = 0; a < n; a++) x[a] = 0;
	
	int p;
	scanf("%d", &p);
	for (a = 0; a < p; a++) {
		scanf("%d", &fase);
		x[fase-1] = 1;
	}
	
	scanf("%d", &p);
	for (a = 0; a < p; a++) {
		scanf("%d", &fase);
		x[fase-1] = 1;
	}
	
	int deu = 0;
	
	for (a = 0; a < n; a++) {
		if (x[a] == 0) deu = 1;		
	}
	
	if (deu == 0) printf("I become the guy.\n");
	else printf("Oh, my keyboard!\n");
	
	return 0;
}
