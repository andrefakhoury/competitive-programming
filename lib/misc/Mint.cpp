// const int MOD = 998244353;
const int MOD = 1e9 + 7;
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
	mint operator+(mint const& m) const { return m.v + v >= MOD ? m.v + v - MOD : m.v + v; }
	mint operator-(mint const& m) const { return m.v - v < 0 ? m.v - v + MOD : m.v - v; }
	mint operator*(mint const& m) const { return (long long) m.v * v % MOD; }
	mint operator/(mint const& m) const { return (*this) * m.inv(); }
	mint operator^(long long m) const { return fpow(*this, m); }
	mint& operator+=(mint const& m) { return (*this) = (*this) + m; }
	mint& operator-=(mint const& m) { return (*this) = (*this) - m; }
	mint& operator*=(mint const& m) { return (*this) = (*this) * m; }
	mint& operator/=(mint const& m) { return (*this) = (*this) / m; }
};

// BE CAREFUL, m.v is INT, overflow is possible on input!
istream& operator>>(istream& in, mint& m) { in >> m.v; m.go(); return in; }
ostream& operator<<(ostream& out, mint m) { return out << m.v; }
