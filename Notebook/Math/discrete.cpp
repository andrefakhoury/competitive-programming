#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// returns the Greates Common Divisor of A and B
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

// extended euclidan algorithm
ll gcd(ll n, ll d, ll& i, ll& j) {
	if (n%d == 0) {
		j = 1;
		i = 0;
		return d;
	} else {
		ll g = gcd(d, n%d, i, j);
		ll ti = i;
		i = j;
		j = ti - (j)*(n/d);
		return g;
	}
}

// returns whether a and b are coprimes 
bool areCoPrimes(ll a, ll b) {
	return gcd(max(a, b), min(a, b)) == 1;
}

// a^b mod m
ll powerMod(ll a, ll b, ll m) {
	a %= m;
	// b %= m-1; // if m is prime
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

// returns n^-1 (mod mod)
ll calcInverseMod(ll n, ll mod) {
	ll i, j;
	gcd(n, mod, i, j);

	while(i < 0) i = (i + mod)%mod;
	return i%mod;
}

bool isPrime(ll n) { // O(sqrt(n))
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}

bool isPseudoPrime(ll a, ll mod) {
	return powerMod(a, mod-1, mod) == 1;
}

// miller rabin primality test of N, according to the bases of the vector
bool isProbablePrime(ll n, vector<ll>& bases) {
	//O(b*logn*logn)

	if (n > 2 && n%2 == 0) return false;
	if (n > 3 && n%3 == 0) return false;
	if (n > 5 && n%5 == 0) return false;
	if (n > 7 && n%7 == 0) return false;

	// decompose n:
	// n = 2^k * q + 1 
	ll k = 0, q = n-1;

	while (q > 0 and q%2 == 0) {
		k++;
		q /= 2;
	}

	for (int i = 0; i < bases.size(); i++) {
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
// vector<ll> bases = {2, 3, 7, 11, 23, 31, 37, 61}; //22 errors in [2..1e7]
// vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 503}; // 2 errors in [2..1e7]