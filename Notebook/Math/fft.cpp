// SPOJ POLYMUL: https://www.spoj.com/problems/POLYMUL/

#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

// A.size() is a power of 2
void fft(vector<cd>& A, bool invert) {
	int n = A.size();
	if (n == 1) return;

	vector<cd> a_even(n/2), a_odd(n/2);
	for (int i = 0; i + i < n; i++) {
		a_even[i] = A[i + i];
		a_odd[i] = A[i + i + 1];
	}

	fft(a_even, invert);
	fft(a_odd, invert);

	double ang = 2 * PI / n;
	if (invert) ang = -ang;
	cd w(1), wn(cos(ang), sin(ang));

	for (int i = 0; i + i < n; i++) {
		A[i] = a_even[i] + w * a_odd[i];
		A[i + n/2] = a_even[i] - w * a_odd[i];
		if (invert) {
			A[i] /= 2;
			A[i + n/2] /= 2;
		}
		w *= wn;
	}
}

using ll = long long;

vector<ll> multiply(vector<ll> const& A, vector<ll> const& B) {
	vector<cd> fa(A.begin(), A.end());
	vector<cd> fb(B.begin(), B.end());

	int n = 1;
	while(n < A.size() + B.size()) n *= 2;

	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);

	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);

	vector<ll> ans(n);
	for (int i = 0; i < n; i++) ans[i] = round(fa[i].real());

	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		vector<ll> a(n+1), b(n+1);
		for (ll& i : a) scanf("%lld", &i);
		for (ll& i : b) scanf("%lld", &i);
		vector<ll> ans = multiply(a, b);
		for (int i = 0; i < n + n + 1; i++) printf("%lld ", ans[i]);
		printf("\n");
	}
}