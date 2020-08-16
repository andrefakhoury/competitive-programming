#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

template <typename T> T add(T x, T y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

template <typename T> T sub(T x, T y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

template <typename T> T mul(T x, T y) { return 1ll * x * y % MOD; }

template <typename T> T inv(T a) {
	T u = 0, v = 1, m = MOD;
	while (a != 0) {
		T t = m / a;
		m -= t * a; std::swap(a, m);
		u -= t * v; std::swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T> T divi(T x, T y) { return mul(x, inv(y)); }
