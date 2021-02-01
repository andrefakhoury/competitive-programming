#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

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

	template<typename T> inline vector<T> multiply(vector<T> const& a, vector<T> const& b) {
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

inline void run_test(int test_number) {
	int n; rd(n);
	vector<ll> a(n + 1), b(n + 1);
	for (ll& i : a) rd(i);
	for (ll& i : b) rd(i);
	vector<ll> ans = FFT::multiply(a, b);
	for (int i = 0; i < n + n + 1; i++) {
		cout << ans[i] << " \n"[i == n + n];
	}
}

int main() {

//#ifndef LOCAL_PC
//	freopen("FILE.in", "r", stdin);
//#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) run_test(i);
}