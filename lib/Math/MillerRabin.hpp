// u64 must fit N. u128 must fit N * N
#define u64 long long
#define u128 __int128

/** Binary exponentiation. O(log y) */
inline u64 fpow(u64 x, u64 y, u64 const MOD) {
	u64 r = 1;
	while(y > 0) {
		if (y&1) r = static_cast<u128>(r) * x % MOD;
		x = static_cast<u128>(x) * x % MOD;
		y /= 2;
	}
	return r;
}

/** Miller Rabin primality test of N base P. O(log d + r) */
inline bool checkComposite(u64 n, u64 a, u64 d, int r) {
	u64 x = fpow(a, d, n);
	if (x == 1 or x == n - 1) return false;
	for (int b = 1; b < r; b++) {
		x = static_cast<u128>(x) * x % n;
		if (x == n - 1) return false;
	}
	return true;
}

/** Miller Rabin. Actually deterministic for 64 bits integer. O(log n) */
bool isProbablePrime(u64 n) {
	if (n < 4) return n == 2 || n == 3;
	if ((n&1) == 0) return false;

	// deterministic for 64 bits. for 32 bit just check {2, 3, 5, 7}
	const static int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

	// (n - 1) = d * 2 ^ r
	u64 d = n - 1;
	int r = 0;
	while ((d&1) == 0) d /= 2, r++;

	for (int const a : base) {
		if (n == a) return true;
		if (n % a == 0) return false;
		if (checkComposite(n, a, d, r)) return false;
	}

	return true;
}

#undef u64
#undef u128