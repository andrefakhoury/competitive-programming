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
	int n, q; rd(n, q);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);

	vector<ll> sum(n + 1);
	ll mx = a[0];
	__int128 tot = 0;
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + a[i];
		tot += a[i];
		mx = max(mx, sum[i + 1]);
	}

	const ll INF = 1e15;
	const int BKSZ = sqrt(n) + 2;
	const int QTBK = (n + BKSZ - 1) / BKSZ;
	vector<pair<ll, ll>> block(QTBK, make_pair(0, -INF));
	for (int i = 0; i < n; i++) {
		block[i / BKSZ].fi += a[i];
		block[i / BKSZ].se = max(block[i / BKSZ].se, block[i / BKSZ].fi);
	}

	auto full_rot = [&](ll x)->ll {
		if (tot <= 0) return mx >= x ? 0 : -1;
		ll lo = 0, hi = 1e9, mi;
		while(lo < hi) {
			mi = (lo + hi) / 2;
			if (tot * mi + mx >= x) hi = mi;
			else lo = mi + 1;
		}
		return lo;
	};

	auto query = [&](ll x)->ll {
		ll rot = full_rot(x);
		if (rot == -1) return -1;

		// primeiro cara X tal que tot * rot + X >= x
		ll prev_sum = 0;
		for (int bk = 0; bk < QTBK; bk++) {
			if (tot * rot + prev_sum + block[bk].se >= x) {
				for (int i = bk * BKSZ; i / BKSZ == bk; i++) {
					if (tot * rot + sum[i + 1] >= x) {
						return rot * n + i;
					}
				}
				return -1;

			}
			prev_sum += block[bk].fi;
		}
		return -1;
	};



	while(q--) {
		ll x; rd(x);
		cout << query(x) << " ";
	}
	cout << "\n";
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