namespace FFT {
	const double PI = acos(-1);

	struct base { // real + imag * i
		double real, imag;
		base() : real(0), imag(0) {}
		base(double x) : real(x), imag(0) {}
		base(double real, double imag) : real(real), imag(imag) {}
		base operator*(base const& b) { return base(real * b.real - imag * b.imag, real * b.imag + imag * b.real); }
		base operator+(base const& b) { return base(real + b.real, imag + b.imag); }
		base operator-(base const& b) { return base(real - b.real, imag - b.imag); }
		base operator/(double const b) { return base(real / b, imag); }
		base& operator*=(base const& b) { return *this = *this * b; }
		base& operator+=(base const& b) { return (real += b.real, imag += b.imag), *this; }
		base& operator-=(base const& b) { return (real -= b.real, imag -= b.imag), *this; }
		base& operator/=(double const b) { return (real /= b), *this; }
	}; // if you don't want to code this struct, use `using base=complex<double>;`

	inline void fft(vector<base>& a, bool invert) {
		int n = a.size();
		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j >= bit; bit >>= 1) j -= bit;
			j += bit;
			if (i < j) swap (a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * PI/len * (invert ? -1 : 1);
			base wlen(cos(ang), sin(ang)), w, u, v;
			for (int i = 0; i < n; i += len) {
				w = 1;
				for (int j = 0; j < len/2; j++) {
					u = a[i+j], v = a[i+j+len/2] * w;
					a[i + j] = u + v;
					a[i + j + len/2] = u - v;
					w *= wlen;
				}
			}
		}

		if (invert) for (int i = 0; i < n; i++) a[i] /= n;
	}

	template<typename T>
	inline vector<T> multiply(vector<T> const& a, vector<T> const& b) {
		vector<base> ca(a.begin(), a.end()), cb(b.begin(), b.end());
		int n = 1;
		while(n < (int) (a.size() + b.size())) n <<= 1;
		ca.resize(n); cb.resize(n);
		fft(ca, false); fft(cb, false);
		for (int i = 0; i < n; i++) ca[i] *= cb[i];
		fft(ca, true);
		vector<T> ans(n);
		for (int i = 0; i < n; i++) ans[i] = llround(ca[i].real);
		return ans;
	}
}