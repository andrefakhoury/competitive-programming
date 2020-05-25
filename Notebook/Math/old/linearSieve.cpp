#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000000;

vector<int> primes;
bool isComposite[MAXN];

void linearSieve(int N) {
	memset(isComposite, 0, sizeof isComposite);
	primes.clear();

	for (int i = 2; i < N; i++) {
		if (!isComposite[i]) primes.push_back(i);
		for (int j = 0; j < (int)primes.size() && i * primes[j] < N; j++) {
			isComposite[i * primes[j]] = true;
			if (i%primes[j] == 0) break;
		}
	}
}