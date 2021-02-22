const int MOD = 998244353;
struct mint {
	int v;
	mint() : v{} {}
	mint(int v) : v(v) { go(); }
	inline void go() { if (abs(v) >= MOD) v %= MOD; if (v < 0) v += MOD; }

	inline static mint fpow(mint x, long long y) { // x ^ y
		mint r = 1;
		for (; y > 0; y /= 2, x *= x) if (y%2 != 0) r *= x;
		return r;
	}
	mint inv() const { return fpow(*this, MOD - 2); }
	mint operator+(mint const& m) const { return v + m.v >= MOD ? v + m.v - MOD : v + m.v; }
	mint operator-(mint const& m) const { return v - m.v < 0 ? v - m.v + MOD : v - m.v; }
	mint operator*(mint const& m) const { return (long long) v * m.v % MOD; }
	mint operator/(mint const& m) const { return (*this) * m.inv(); }
	mint operator^(long long m) const { return fpow(*this, m); }
	mint& operator+=(mint const& m) { return (*this) = (*this) + m; }
	mint& operator-=(mint const& m) { return (*this) = (*this) - m; }
	mint& operator*=(mint const& m) { return (*this) = (*this) * m; }
	mint& operator/=(mint const& m) { return (*this) = (*this) / m; }
};