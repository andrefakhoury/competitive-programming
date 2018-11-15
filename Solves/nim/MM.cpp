#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int p[MAXN];

int nimSum(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) sum = sum^p[i];
	return sum;
}

int predict(int n) {
	if (nimSum(n) != 0) return 1;
	return 2;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, sum = 0; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", p+i);
			sum += p[i];
		}

		if (sum == n) printf("%s\n", sum%2 == 0 ? "John" : "Brother");
		else printf("%s\n", predict(n) == 1 ? "John" : "Brother");
	}
}