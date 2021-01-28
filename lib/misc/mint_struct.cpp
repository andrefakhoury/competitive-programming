const int MOD = 998244353;
struct mint {
	int v;
	mint() : v{} {}
	mint(int v) : v(v) { go(); }
	inline void go() { if (abs(v) >= MOD) v %= MOD; if (v < 0) v += MOD; }
	mint operator+(mint const& m) const { return m.v + v >= MOD ? m.v + v - MOD : m.v + v; }
	mint operator-(mint const& m) const { return m.v - v < 0 ? m.v - v + MOD : m.v - v; }
	mint operator*(mint const& m) const { return 1ll * m.v * v % MOD; }
	mint& operator+=(mint const& m) { return (*this) = (*this) + m; }
	mint& operator-=(mint const& m) { return (*this) = (*this) - m; }
	mint& operator*=(mint const& m) { return (*this) = (*this) * m; }
};