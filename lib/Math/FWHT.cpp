#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl
using ll = long long;
using pii = pair<int, int>;

/**
 * Fast Walsh-Hamadard Transform. N must be a power of 2. O(n logn)
 * (ax^i) (*) (bx^j) = ab * x^{i (op) j}, where op can be:
 *     Xor: u = a + b, v = a - b
 *      Or: u = a,     v = a + b
 *     And: u = b,     v = a + b
 * Used for xor-convolution or something like that.
 */
void fwht(vector<ll>& v, bool invert) {
	int n = v.size();
	for (int mlen = 1; mlen + mlen <= n; mlen <<= 1) {
		for (int i = 0; i < n; i += mlen + mlen) {
			for (int j = 0; j < mlen; j++) {
				ll a = v[i + j], b = v[i + j + mlen]; // solving (a + bx) for x = {1, -1}.
				v[i + j] = a + b; // when x = 1, a+bx = a+b
				v[i + j + mlen] = a - b; // when x = -1, a+bx = a-b
				if (invert) v[i + j] >>= 1, v[i + j + mlen] >>= 1; // if u=a+b, v=a-b => a=(u+v)/2, b=(u-v)/2
			}
		}
	}
}

/** performs xor convolution and returns vector of frequency for each number.
 *                                n = 2^k, where a_i, b_i <= 2^k for each i.
 * basically is: for x in a: for y in b: ans[x^y]++; but in O(n logn)
 */
vector<ll> xor_convolution(vector<ll> const& a, vector<ll> const& b, int n) {
	vector<ll> f1(n), f2(n);
	for (ll x : a) f1[x]++;
	for (ll x : b) f2[x]++;
	fwht(f1, false);
	fwht(f2, false);
	for (int i = 0; i < n; i++) f1[i] *= f2[i];
	fwht(f1, true);
	return f1;
}

int main() {
	int n = 1e6;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = rand()%n;
		b[i] = rand()%n;
	}

	auto ck = clock();
	vector<ll> c = xor_convolution(a, b, 1 << (32 - __builtin_clz(n)));
	double tempo = double(clock() - ck) / CLOCKS_PER_SEC;
	printf("Time elapsed: %.5lf\n", tempo);

	ll ans = 0;
	for (int i = 0; i < (int) c.size(); i++) ans += c[i];
	printf("%lld\n", ans);
}
