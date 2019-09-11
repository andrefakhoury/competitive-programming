// Given a range [l, r] tells the element that has
// that countains the maximum number of divisors

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

int count(int n, int prime) {
	int ret = 0;
	while(n%prime == 0) {
		n /= prime;
		ret++;
	}
	return ret;
}

pair<int, int> solve(int l, int r) {
	unordered_map<int, int> ndiv;
	int ans = 0;

	for (int p : primes) {
		int i = l/p * p;
		if (i < l) i += p;

		for (; i <= r; i += p) {
			int x = count(i, p);

			if (ndiv[i] == 0) ndiv[i] = 1;

			ndiv[i] = ndiv[i] * (x + 1);
			if (ndiv[i] == ndiv[ans]) ans = min(ans, i);
			else if (ndiv[i] > ndiv[ans]) ans = i;
		}
	}

	return make_pair(ans, ndiv[ans]);
}


int main() {
	sieve(MAXN);

	int t; scanf("%d", &t);
	while(t--) {
		int l, r; scanf("%d%d", &l, &r);
		pair<int, int> ans = solve(l, r);
		if (l == r && l == 1) ans = make_pair(1, 1);
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, ans.first, ans.second);
	}

	return 0;
}