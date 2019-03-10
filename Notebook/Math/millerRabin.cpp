#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int bases[] = {61, 7, 2};

// miller rabin primality test of N, according to the bases of the vector
bool isProbablePrime(ll n, vector<ll>& bases) {

	if (n > 2 && n%2 == 0) return false;
	if (n > 3 && n%3 == 0) return false;
	if (n > 5 && n%5 == 0) return false;
	if (n > 7 && n%7 == 0) return false;

	// n = 2^k * q + 1 
	ll k = 0, q = n-1;

	while (q > 0 and q%2 == 0) {
		k++;
		q /= 2;
	}

	for (ll i = 0; i < bases.size(); i++) {
		ll b = bases[i];

		if (n == b) continue;

		ll last = -1, p2 = 1;
		for (ll j = 0; j <= k; j++) {

			ll cur = powerMod(b, p2 * q, n);

			p2 *= 2;

			if (last != -1) {
				if (last == n-1 && cur != 1) return false;
				if (last == 1 && cur != 1) return false;
			}

			last = cur;
		}

		if (last != 1) return false;
	}

	return true;
}

bool isPrime(ll n) { // O(sqrt(n))
	if (n == 1) return false;
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}

int main() {
	ll x;
	while (cin >> x) {
		cout << (isPrime(x) ? "Prime" : "Not Prime") << endl;
	}

	return 0;
}