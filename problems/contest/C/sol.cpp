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

struct Parabola {
	ll a, b, c;
	inline void read() { rd(a, b, c); }
	inline ll eval(ll x) const { return a * x * x + b * x + c; }
};

inline void run_test(int test_number) {
	int n; rd(n);
	vector<Parabola> a(n);
	for (int i = 0; i < n; i++) a[i].read();

	const ll X = 1e5;
	const int N = X + X + 1;
	vector<int> better(N);

	auto get_better = [&](int i, int x) {
		int& b = better[x + X];
		if(a[i].eval(x) > a[b].eval(x)) b = i;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			ll A = a[i].a - a[j].a, B = a[i].b - a[j].b, C = a[i].c - a[j].c;
			if (A) {
				ll delta = B * B - 4 * A * C;
				if (delta > 0) {
					double x1 = (-1.0 * B + sqrt(delta)) / A / 2;
					double x2 = (-1.0 * B - sqrt(delta)) / A / 2;
					auto go = [&](ll x) { get_better(i, clamp(x, -X, X)); };
					auto gogo = [&](ll x) { go(x-1), go(x), go(x+1); };
					gogo(llround(x1)), gogo(llround(x2));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) get_better(i, -X), get_better(i, X);
	for (int i = 1; i < N; i++) get_better(better[i - 1], i - X);
	for (int i = N-2; i >= 0; i--) get_better(better[i + 1], i - X);

	int q; rd(q);
	for (int i = 0; i < q; i++) {
		int x; rd(x);
		int& b = better[x + X];
		print(b, a[b].eval(x));
	}
}

int main() {
#ifndef LOCAL_PC
	freopen("parabolas.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) {
		cout << "Case " << i << ":\n";
		run_test(i);
	}
}