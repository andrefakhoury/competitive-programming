mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint64(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng64); }

/** Finds a divisor d (1 < d < n) of n. O(n^(1/4) * log(n)) */
ll pollard_rho(ll n) {
	if (n%2 == 0) return 2;

	ll a = randint64(2ll, n-1); // tortoise
	ll b = a; // hare
	ll c = randint64(1ll, n-1);
	ll g = 1;

	auto f = [c, n](ll k) { return (k * k + c) % n; };

	while(g == 1) {
		a = f(a);
		b = f(f(b));
		g = gcd(abs(b-a), n);
	}

	return g == n ? pollard_rho(n) : g;
}