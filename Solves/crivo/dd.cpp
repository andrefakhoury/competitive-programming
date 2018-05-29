#include <bits/stdc++.h>

using namespace std;

#define N 100000
long long int f[N];

void fact(int n){
	int p;

	// For every prime p up to sqrt(n).
	for (p = 2; p * p <= n; p++){
		// While p divides n, keep dividing n by p and increasing the number of p factors.
		while (n % p == 0){
			n /= p;
			f[p]++;
		}
	}

	// If n is not 1 by now, then it is a prime factor.
	if (n > 1){
		f[n]++;
	}
}

int main() {
	fact(N);
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF) {
		
		printf("%d %d\n", x, f[y]);
		
		if (f[y]%x == 0)
			printf("%d divides %d!\n", y, x);
		else
			printf("%d does not divide %d!\n", y, x);
	}
	
    
}
