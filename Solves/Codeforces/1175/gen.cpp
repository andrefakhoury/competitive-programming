#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));

	int n = 1e5;
	printf("%d\n", n);

	int qtt = 0, qtf = 0, qta = 0, qte = 0;
	for (int i = 1; i <= n; i++) {
		int aaa = rand()%100 + 1;

		int op = rand()%6;

		if (n-i < qtt) {
			printf("end\n"); qte++;
			qtt--;
			continue;
		}

		if (op == 0) {
			if (n-i < qtt) {
				printf("end\n"); qte++;
				qtt--;
			} else if (qtt < n-i-2) {
				printf("for %d\n", aaa); qtf++;
				qtt++;
			} else {
				printf("add\n"); qta++;
			}
		} else if (op == 1) {
			if (qtt > 0) {
				printf("end\n"); qte++;
				qtt--;
			} else {
				printf("add\n"); qta++;
			}
		} else {
			printf("add\n"); qta++;
		}
	}
}