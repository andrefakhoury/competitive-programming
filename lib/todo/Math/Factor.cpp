using ll = long long;
namespace Factor {
	vector<int> primes, mu, isPrime;

	inline ll mul(ll a, ll b, ll p) {
		if (p <= 1000000000) return a * b % p;
		else if (p <= 1000000000000ll) return (((a * (b >> 20) % p) << 20) + (a * (b & ((1 << 20) - 1)))) % p;
		else {
			ll d = (ll) floor(a * (long double) b / p + 0.5);
			ll ret = (a * b - d * p) % p;
			if (ret < 0) ret += p;
			return ret;
		}
	}

	inline ll fpow(ll x, ll y, ll mod) {
		ll r = 1;
		for (; y > 0; y /= 2, x = mul(x, x, mod)) if (y&1) r = mul(r, x, mod);
		return r;
	}

	/** Miller Rabin primality test of N base P. O(log d + r) */
	inline bool checkComposite(ll n, ll a, ll d, int r) {
		ll x = fpow(a, d, n);
		if (x == 1 or x == n - 1) return false;
		for (int b = 1; b < r; b++) {
			x = mul(x, x, n);
			if (x == n - 1) return false;
		}
		return true;
	}

	/** Miller Rabin. Actually deterministic for 64 bits integer. O(log n) */
	inline bool isProbablePrime(ll n) {
		if (n < 4) return n == 2 || n == 3;
		if ((n&1) == 0) return false;

		// deterministic for 64 bits. for 32 bit just check {2, 3, 5, 7}
		const static int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

		// (n - 1) = d * 2 ^ r
		ll d = n - 1;
		int r = 0;
		while ((d&1) == 0) d /= 2, r++;

		for (int const a : base) {
			if (n == a) return true;
			if (n % a == 0) return false;
			if (checkComposite(n, a, d, r)) return false;
		}

		return true;
	}

	// Sieve of Eratosthenes. O(n log(logn))
	inline void sieve(const int N) {
		isPrime.assign(N + 1, 1);
		isPrime[0] = isPrime[1] = 0;
		for (int i = 2; i * i <= N; i++) if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= N; j += i) isPrime[j] = 0;
		}
	}

	/** Möbius function. O(n logn)
	 - mu(n) = 1 if n is square-free w/ even prime factors
	 - mu(n) = -1 if n is square-free w/ odd prime factors
	 - mu(n) = 0 if has squared prime factor
	 	(n is square-free if each prime appears only once) */
	inline void mobius(const int N) {
		mu.resize(N + 1);
		mu[1] = 1;
		for (int i = 1; i <= N; i++)
			for (int j = i + i; j <= N; j += i)
				mu[j] -= mu[i];
	}

	// Euler's totient phi(n). O(sqrt(N))
	inline ll phi(ll n) {
		ll r = n;
		for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
			while(n % i == 0) n /= i;
			r -= r / i;
		}
		if (n > 1) r -= r / n;
		return r;
	}
}
