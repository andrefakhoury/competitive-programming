#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 1e6;

bool isPrime[MAXN];
vector<int> primes;

void sieve(int n) {
	fill(isPrime, isPrime + MAXN, true);

	for (int i = 2; i < n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j < n; j += i)
				isPrime[j] = false;
			primes.push_back(i);
		}
	}
}

void segmentedSieve(int l, int r) {
	int ans = 0;

	for (int p : primes) {
		int i = l/p * p;
		if (i < l) i += p;

		for (; i <= r; i += p) {
			// i is a multiple of p in range [l, r]
			// you can just check isPrime[i] to false
		}
	}
}


int main() {
	sieve(MAXN);

	return 0;
}