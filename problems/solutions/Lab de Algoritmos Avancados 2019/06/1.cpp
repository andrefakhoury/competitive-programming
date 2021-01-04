#include <stdio.h>
using namespace std;

const int MAXN = 1e6 + 50;

bool notPrime[MAXN];

int rev(int i) {
	int num = 0;
	while(i > 0) {
		num = num * 10 + i%10;
		i /= 10;
	}
	return num;
}

void sieve(int N) {
	for (int i = 2; i <= N; i++) {
		if (notPrime[i]) continue;
		for (int j = 2 * i; j <= N; j += i)
			notPrime[j] = true;
	}
}

int main() {

	sieve(MAXN-1);

	int n;
	while(~scanf("%d", &n))	 {
		if (rev(n) != n and !notPrime[n] && !notPrime[rev(n)]) printf("%d is emirp.\n", n);
		else if (!notPrime[n]) printf("%d is prime.\n", n);
		else printf("%d is not prime.\n", n);
	}
}