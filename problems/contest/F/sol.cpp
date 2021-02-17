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

const int MAXN = 3e5 + 15;

struct Bit {
	vector<ll> bt;
	Bit(int n) : bt(n + 10) {}
	void add(int i, ll x) {
		for (i++; i < (int) bt.size(); i += i&-i) {
			bt[i] += x;
		}
	}
	ll qry(int i) {
		ll r = 0;
		for (i++; i > 0; i -= i&-i) r += bt[i];
		return r;
	}
	ll qry(int l, int r) {
		if (l > r) return 0;
		return qry(r) - qry(l-1);
	}
};

inline void run_test(int test_number) {
	int n; rd(n);
	map<int, int> f;
	for (int i = 0; i < n; i++) {
		int x; rd(x);
		f[x]++;
	}

	Bit qtt(n), sum(n);
	for (auto p : f) {
		qtt.add(p.se, 1);
		sum.add(p.se, p.se);
	}

	ll ans = n;
	for (int c = 1; c <= n; c++) {
		ll cur = sum.qry(1, c - 1) + sum.qry(c + 1, n) - qtt.qry(c + 1, n) * c;
		assert(cur >= 0 && cur <= n);
		ans = min(ans, cur);
	}
	print(ans);
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