#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int t = rand()%100 + 1;
	printf("%d\n", t);
	while(t--) {
		int n = rand()%10 + 2;
		printf("%d\n", n);
		while(n--) {
			printf("%d ", rand()%3 + 1);
		} printf("\n");
	}
}