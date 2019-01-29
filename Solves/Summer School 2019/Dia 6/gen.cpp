#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));

	int n = 250000;
	int m = rand()%n;

	while(n--) {
		printf("%c", rand()%26 + 'a');
	} printf("\n");

	while(m--) {
		printf("%c", rand()%26 + 'a');
	} printf("\n");
}