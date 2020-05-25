////////////// ------------------ //////////////
////////////// - mod operations - //////////////
////////////// ------------------ //////////////

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int inv(int x) {
	int y = MOD-2;
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

////////////// --------------- //////////////
////////////// - mint struct - //////////////
////////////// --------------- //////////////

template<int const MOD>
struct Modint {
	int val;
	
	Modint() : val() {}
	Modint(int val) : val(val) {}
	Modint(ll val) : val(val) {}
	Modint(char val) : val(val) {}

	inline Modint operator*(Modint const& rhs) { return ll(val) * rhs.val % MOD; }
	inline Modint operator+(Modint const& rhs) { return val + rhs.val >= MOD ? val + rhs.val - MOD : val + rhs.val; }
	inline Modint& operator+=(Modint const& rhs) { return *this = (*this) + rhs; }
	inline Modint& operator*=(Modint const& rhs) { return *this = (*this) * rhs; }
	inline bool operator==(Modint const& rhs) { return val == rhs.val; }

	inline Modint fastPow(int y) {
		Modint ret = 1;
		Modint x = val;
		while(y) {
			if (y&1) ret *= x;
			x *= x;
			y /= 2;
		}
		return ret;
	}

	inline Modint inv() {
		return fastPow(MOD-2);
	}
}; template<int const MOD> ostream& operator<<(ostream& os, Modint<MOD> const& m) { return os << m.val; }

using mint = Modint<1000000007>;