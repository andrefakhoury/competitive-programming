template <typename T> struct Frac {
	T num, den;
	Frac() : num{0}, den{1} {}

	template <typename M>
	Frac(M num, M den) : num(static_cast<T>(num)), den(static_cast<T>(den)) { normalize(); }

	inline void normalize() {
		assert(den != 0);
		if (num == 0) { den = 1; return; }

		T g = __gcd(num, den);
		num /= g;
		den /= g;
	}

	// +, -, /, *
	Frac operator+(Frac const& frac) const {
		Frac ret;
		ret.den = den / __gcd(den, frac.den) * frac.den;
		ret.num = num * (ret.den / den) + frac.num * (ret.den / frac.den);
		return ret;
	}

	Frac operator-(Frac const& frac) const {
		return (*this) + Frac{-frac.num, frac.den};
	}

	Frac operator*(Frac const& frac) const {
		Frac ret{num * frac.num, den * frac.den};
		ret.normalize();
		return ret;
	}

	Frac operator/(Frac const& frac) const {
		Frac ret{num * frac.den, den * frac.num};
		ret.normalize();
		return ret;
	}

	inline Frac inv() const { return Frac{den, num}; }

	Frac& operator+=(Frac const& frac) { return (*this) = (*this) + frac; }
	Frac& operator-=(Frac const& frac) { return (*this) = (*this) - frac; }
	Frac& operator*=(Frac const& frac) { return (*this) = (*this) * frac; }
	Frac& operator/=(Frac const& frac) { return (*this) = (*this) / frac; }
};

template <typename T> std::ostream& operator<<(std::ostream& stream, const Frac<T>& frac) {
	return stream << frac.num << "/" << frac.den;
}