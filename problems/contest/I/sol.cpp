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

inline void run_test(int test_number) {
	int n; rd(n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	for (int i = 0; i < n; i++) rd(b[i]);

	auto check = [&](int k) {
		bool prev = true;
		for (int i = n-1; i >= 0; i--) {
			int cur_a = a[i] + k;
			int cur_b = b[i];
			if (cur_a != cur_b) {
				prev = cur_a > cur_b;
			}
		}
		return prev;
	};

	int lo = 0, hi = 1e9, mi;
	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (check(mi)) hi = mi;
		else lo = mi + 1;
	}
	print(hi);

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}