template<const int MOD>
struct Mint {
	int v;
	Mint() : v{} {}
	Mint(int v) : v(v) { go(); }
	inline void go() { if (abs(v) >= MOD) v %= MOD; if (v < 0) v += MOD; }

	inline static Mint fpow(Mint x, long long y) { // x ^ y
		Mint r = 1;
		for (; y > 0; y /= 2, x *= x) if (y%2 != 0) r *= x;
		return r;
	}
	Mint inv() const { return fpow(*this, MOD - 2); }
	Mint operator+(Mint const& m) const { return v + m.v >= MOD ? v + m.v - MOD : v + m.v; }
	Mint operator-(Mint const& m) const { return v - m.v < 0 ? v - m.v + MOD : v - m.v; }
	Mint operator*(Mint const& m) const { return (long long) v * m.v % MOD; }
	Mint operator/(Mint const& m) const { return (*this) * m.inv(); }
	Mint operator^(long long m) const { return fpow(*this, m); }
	Mint& operator+=(Mint const& m) { return (*this) = (*this) + m; }
	Mint& operator-=(Mint const& m) { return (*this) = (*this) - m; }
	Mint& operator*=(Mint const& m) { return (*this) = (*this) * m; }
	Mint& operator/=(Mint const& m) { return (*this) = (*this) / m; }
};