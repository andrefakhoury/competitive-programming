#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("I hate ");
	for (int i = 2; i <= n; i++){
		if (i%2 == 1) {
			printf("that I hate ");
		} else {
			printf("that I love ");
		}
	}
	
	printf("it\n");
	
	return 0;
}
