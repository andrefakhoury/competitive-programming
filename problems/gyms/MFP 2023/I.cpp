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

template<class T> void DBG(T&& x) { cerr << x << ' '; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

/** Binary Indexed Tree, aka Fenwick Tree */
template<typename T>
struct BIT {
	std::vector<T> bt;
	int n;

	BIT(int n) : n{n} {
		bt.resize(n + 2);
	}

	inline void init(int sz) {
		n = sz;
		bt.assign(n + 2, 0);
	}

	inline void update(int i, T k) {
		for (i++; i <= n + 1; i += i&-i)
			bt[i] += k;
	}

	inline T query(int i) {
		T ret{};
		for (i++; i; i -= i&-i)
			ret += bt[i];
		return ret;
	}

	inline T query(int l, int r) {
		if (l > r) return 0;
		return query(r) - query(l-1);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int q; rd(q);
	vector<pii> qrs(q);

	vector<int> allx;
	for (int i = 0; i < q; i++) {
		char op; rd(op);
		int x; rd(x);
		allx.pb(x);
		if (op == '+') qrs[i] = {x, 1};
		else qrs[i] = {x, -1};
	}

	sort(allx.begin(), allx.end());
	allx.erase(unique(allx.begin(), allx.end()), allx.end());

	const int N = allx.size();

	BIT<ll> bqtt(N), bsum(N);

	auto get_ans = [&](int val) {
		const int idx = upper_bound(allx.begin(), allx.end(), val) - allx.begin() - 1;
		return val * bqtt.query(0, idx) - bsum.query(0, idx) + bsum.query(idx+1, N) - val * bqtt.query(idx+1, N);
	};
	auto find_median = [&]() {
		int total = bqtt.query(0, N);

		int lo = 0, hi = N - 1, mi;
		while(lo < hi) {
			mi = (lo + hi) / 2;
			if (bqtt.query(0, mi)*2 >= total) hi = mi;
			else lo = mi + 1;
		}

		if (bqtt.query(0, mi)*2 == total) return (allx[lo] + allx[lo + 1]) / 2;
		else return allx[lo];
	};


	for (auto [x, delta]: qrs) {
		int idx = lower_bound(allx.begin(), allx.end(), x) - allx.begin();
		
		bqtt.update(idx, delta);
		bsum.update(idx, delta * x);

		if (bqtt.query(0, N) == 0) {
			print(-1);
			continue;
		}

		int median = find_median();
		ll ans = min({
			get_ans(median),
			get_ans(median-1),
			get_ans(median+1)
		});

		print(ans);
	}
}
