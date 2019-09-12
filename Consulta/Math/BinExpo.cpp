ll fastExp(ll a, ll b, ll m) {
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