const int MOD = 1e9 + 7;

// Binary exponentiation. O(logn)
inline int fastpow(int x, int y) {
	x %= MOD;
	// y %= MOD-1; // if MOD is prime

	int ret = 1;
	while(y) {
		if (y&1) ret = ll(ret) * x % MOD;
		x = ll(x) * x % MOD;
		y /= 2;
	}

	return ret;
}