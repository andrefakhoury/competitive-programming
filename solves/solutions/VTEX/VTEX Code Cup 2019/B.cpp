#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e6 + 5;

ll mmc(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}

struct frac {
	ll num, den;
	frac() {
		num = 0, den = 1;
	}

	frac(ll a, ll b) {
		num = a, den = b;
	}

	frac(const frac& a) {
		num = a.num, den = a.den;
	}

	void print() {
		cout << num << '/' << den << endl;
	}
};

frac reduce(frac a) {
	bool pos = a.num < 0;

	a.num = abs(a.num);
	a.den = abs(a.den);

	ll g;
	while (g = __gcd(a.num, a.den), g != 1) {
		a.num /= g;
		a.den /= g;
	}

	if (pos) a.num *= -1;

	return a;
}

frac sub(frac a, frac f) {
	if (f.num == 0) return a;
	if (a.num == 0) return f;

	ll aux_den = mmc(abs(a.den), abs(f.den));

	a.num *= aux_den / a.den;
	f.num *= aux_den / f.den;

	a.den = aux_den;
	a.num -= f.num;

	return reduce(a);
}

frac mul(frac a, frac f) {
	return reduce(frac(a.num * f.num, a.den * f.den));
}

frac add(frac a, frac f) {
	if (f.num == 0) return a;
	if (a.num == 0) return f;

	ll aux_den = mmc(abs(a.den), abs(f.den));

	a.num *= aux_den / a.den;
	f.num *= aux_den / f.den;

	a.den = aux_den;
	a.num += f.num;

	return reduce(a);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int k, A, B, C; cin >> k >> A >> B >> C;
	frac ans(0, 0);

	for (int i = 1; i <= k; i++) {
		int lo = 1, hi = k, mi;

		while (lo <= hi) {
			mi = (lo * B + hi * A) / (A + B);

			if (mi == i) {
				ans = add(ans, frac(C, hi - lo + 1));
				break;
			} else if (mi < i) {
				ans = sub(ans, frac(A, hi - lo + 1));
				lo = mi + 1;
			} else if (mi > i) {
				ans = sub(ans, frac(B, hi - lo + 1));
				hi = mi - 1;
			}
		}
	}

	ans.print();
}