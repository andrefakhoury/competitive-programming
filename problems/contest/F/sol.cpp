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

const ll MOD = 1e9 + 7;

inline ll run_test(int test_number) {
	ll s1, s2, l, r; rd(s1, s2, l, r);
	if (s1 == s2) return 0;
	if (s1 > s2) swap(s1, s2);
	s1 = __builtin_ctzll(s1);
	s2 = __builtin_ctzll(s2);

	auto getQtt = [](ll n, int bit)->ll {
		ll gp1 = 1ll << bit, gp2 = gp1 << 1ll;
		return ((n + 1) / gp2) * gp1 + max(0ll, (n + 1) % gp2 - gp1);
	};

	auto get0 = [&getQtt](ll n, int bit) { return n < 0 ? 0 : n - getQtt(n, bit) + 1; };
	auto get1 = [&getQtt](ll n, int bit) { return n < 0 ? 0 : getQtt(n, bit); };
	auto get0lr = [&](ll l, ll r, int bit) { return l > r ? 0 : get0(r, bit) - get0(l-1, bit); };
	auto get1lr = [&](ll l, ll r, int bit) { return l > r ? 0 : get1(r, bit) - get1(l-1, bit); };

	auto gogo1 = [&](ll n, int b1, int b2)->ll { // b1 > b2
		if (n < 0) return 0;

		ll gp1 = 1ll << b1, gp2 = gp1 << 1ll;
		ll qt_groups = (n + 1) / gp2;
		ll ans = qt_groups * get0(gp1, b2);
		ans += get0lr(qt_groups * gp2 + gp1 - 1, n, b2);
		return ans;
	};

	auto gogo2 = [&](ll n, int b1, int b2)->ll { // b1 > b2
		if (n < 0) return 0;

		ll gp1 = 1ll << b1, gp2 = gp1 << 1ll;
		ll qt_groups = (n + 1) / gp2;
		ll ans = qt_groups * get1(gp1, b2);
		ans += get1lr(qt_groups * gp2 - 1, n, b2);
		return ans;
	};

	auto get_qtt1 = [&gogo1](ll l, ll r, int b1, int b2) { return gogo1(r, b1, b2) - gogo1(l-1, b1, b2); };
	auto get_qtt2 = [&gogo2](ll l, ll r, int b1, int b2) { return gogo2(r, b1, b2) - gogo2(l-1, b1, b2); };

	ll ans = 0;
	for (int i = 0; i <= 43; i++) {
		ll qtt = get_qtt1(l, r, i + s2 - s1, i) + get_qtt2(l, r, i + s2 - s1, i);
		__int128 x = 1ll << (i + s2 - s1);

		ans += qtt * x % MOD;
		ans %= MOD;
	}

	return ans;
}

int main() {
#ifndef LOCAL_PC
	freopen("geometry.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) print(run_test(i));
}

