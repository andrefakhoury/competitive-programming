#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000005;

vector<int> primes;
bool notPrime[MAXN];

void sieve(int N) {
	for (int i = 2; i <= N; i++) {
		if (notPrime[i]) continue;
		primes.push_back(i);
		for (int j = 2 * i; j <= N; j += i)
			notPrime[j] = true;
	}
}