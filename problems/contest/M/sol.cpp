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
	string s; rd(s);

	auto check = [&s](int n) {
		int qtd = (n / 9) + (n % 9 ? 1 : 0);
		if (qtd != (int) s.size()) return qtd < (int) s.size();
		string s1 = string(n/9, '9');
		if (n % 9) s1.insert(s1.begin(), (n % 9) + '0');
		return s1 <= s;
	};

	int lo = 1, hi = 1e6, mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(mi)) lo = mi;
		else hi = mi - 1;
	}
	print(lo);
}

int main() {

#ifndef LOCAL_PC
	freopen("lis.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}