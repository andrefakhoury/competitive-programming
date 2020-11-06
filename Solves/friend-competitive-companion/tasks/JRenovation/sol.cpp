#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

template<typename T>
class BIT {
public:
	std::vector<T> bt;
	int n;

	BIT(int n) : n{n} {
		bt.resize(n + 2);
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
		return query(r) - query(l-1);
	}
};

int main() {
	int n, m; rd(n, m);
	vector<ll> a(n);
	vector<pair<ll, ll>> b(m);
	for (int i = 0; i < n; i++) rd(a[i]);
	for (int i = 0; i < m; i++) rd(b[i].fi);
	for (int i = 0; i < m; i++) rd(b[i].se);
	sort(b.begin(), b.end(), [](auto const& a, auto const& b) {
		return a.se < b.se;
	});

	vector<pair<ll, int>> mx(n);
	for (int i = n-1; i >= 0; i--) {
		mx[i] = {a[i], i};
		if (i != n-1) mx[i] = max(mx[i], mx[i+1]);
	}

	vector<pair<ll, ll>> v;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (mk(a[i], i) == mx[i]) {
			v.eb(a[i], sum);
			sum = 0;
		}
	}

	auto get = [&](ll k) {
		int lo = 0, hi = n - 1, mi;
		while(lo < hi) {
			mi = (lo + hi + 1) / 2;
			if (v[mi].fi >= k) lo = mi;
			else hi = mi - 1;
		}
		return lo;
	};

	n = v.size();

	BIT<ll> bt(n);
	for (int i = 0; i < n; i++) {
		bt.update(i, v[i].se);
	}

	vector<vector<int>> ev(n);

	set<int> notzero = {-1};
	for (int i = 0; i < n; i++) notzero.insert(i);

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int j = get(b[i].fi);
		if (v[j].fi < b[i].fi) continue;

		auto ant = [&](int j) {
			return *prev(notzero.upper_bound(j));
		};

		if (bt.query(0, j) >= b[i].se) {
			for (; b[i].se > 0 && j >= 0; j = ant(j)) {
				ll cur = min(v[j].se, b[i].se);
				bt.update(j, -cur);
				v[j].se -= cur;
				if (v[j].se == 0) notzero.erase(j);
				b[i].se -= cur;
			}

			ans++;
		}
	}

	printf("%d\n", ans);
}
