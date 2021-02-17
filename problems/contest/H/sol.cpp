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

inline void run_test(int test_number) {
	int n, m; rd(n, m);
	vector<string> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	vector<vector<mint>> ans(n, vector<mint>(m));

	ans[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (i || j) {
			if (i && a[i-1][j] == '.') ans[i][j] += ans[i-1][j];
			if (j && a[i][j-1] == '.') ans[i][j] += ans[i][j-1];
		}
	}
	print(ans[n-1][m-1]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}