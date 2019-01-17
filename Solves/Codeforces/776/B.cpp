#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;
bool isPrime[MAXN];
int color[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < MAXN; i++) isPrime[i] = true;

	for (int i = 2; i <= n+1; i++) {
		if (!isPrime[i]) continue;
		color[i] = 1;
		for (int j = 2*i; j <= n+1; j+=i) {
			isPrime[j] = false;
			color[j] = 2;
		}
	}
	if (n <= 2) printf("1\n");
	else printf("2\n");

	for (int i = 2; i <= n+1; i++) {
		printf("%d ", color[i]);
	} printf("\n");
}