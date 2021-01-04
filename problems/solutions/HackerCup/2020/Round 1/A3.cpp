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
using pii = pair<ll, ll>;
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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 4e6 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll segmax[4 * MAXN];
inline void prop_max(int p, int i, int j) {
	if (segmax[p]) {
		if (i != j) {
			segmax[p + p] = segmax[p];
			segmax[p + p + 1] = segmax[p];
			segmax[p] = 0;
		}
	}
}

void update_max(int p, int i, int j, int l, int r, ll x) {
	prop_max(p, i, j);
	if (i > j or i > r or j < l) return;
	if (i >= l && j <= r) {
		segmax[p] = x;
		prop_max(p, i, j);
	} else {
		int m = (i + j) / 2;
		update_max(p + p, i, m, l, r, x);
		update_max(p + p + 1, m + 1, j, l, r, x);
	}
}

ll query_max(int p, int i, int j, int k) {
	prop_max(p, i, j);
	if (i == j) return segmax[p];
	int m = (i + j) / 2;
	if (k <= m) return query_max(p + p, i, m, k);
	else return query_max(p + p + 1, m + 1, j, k);
}

ll segsum[4 * MAXN];
ll prpsum[4 * MAXN];
inline void prop_sum(int p, int i, int j) {
	if (prpsum[p] != -1) {
		segsum[p] = prpsum[p];
		if (i != j) {
			prpsum[p + p] = prpsum[p];
			prpsum[p + p + 1] = prpsum[p];
		}
		prpsum[p] = -1;
	}
}

void update_sum(int p, int i, int j, int l, int r, ll x) {
	prop_sum(p, i, j);
	if (i > j or i > r or j < l) return;
	if (i >= l && j <= r) {
		prpsum[p] = x;
		prop_sum(p, i, j);
	} else {
		int m = (i + j) / 2;
		update_sum(p + p, i, m, l, r, x);
		update_sum(p + p + 1, m + 1, j, l, r, x);
		segsum[p] = segsum[p + p] + segsum[p + p + 1];
	}
}

ll query_sum(int p, int i, int j, int l, int r) {
	prop_sum(p, i, j);
	if (i > j or i > r or j < l) return 0;
	if (i >= l && j <= r) return segsum[p];

	int m = (i + j) / 2;
	ll L = query_sum(p + p, i, m, l, r);
	ll R = query_sum(p + p + 1, m + 1, j, l, r);
	return L + R;
}

ll n, k;
ll l[MAXN];
ll h[MAXN];
ll w[MAXN];
ll p[MAXN];

inline void read(ll* v) {
	for (int i = 1; i <= k; i++) rd(v[i]);
	ll a, b, c, d; rd(a, b, c, d);
	for (int i = k + 1; i <= n; i++)
		v[i] = (a * v[i - 2] + b * v[i - 1] + c) % d + 1;
}

inline void _solve_(int __ntest__) {
	mset(segmax, 0);
	mset(segsum, 0);
	mset(prpsum, -1);

	rd(n, k);
	read(l); read(w); read(h);

	vector<ll> all_points;
	for (int i = 1; i <= n; i++) {
		all_points.push_back(l[i]);
		all_points.push_back(l[i] + w[i]);
		all_points.push_back(l[i] + 1);
		all_points.push_back(l[i] + w[i] - 1);
	}
	sort(all_points.begin(), all_points.end());
	all_points.erase(unique(all_points.begin(), all_points.end()), all_points.end());
	auto get_compressed = [&](ll x) {
		return lower_bound(all_points.begin(), all_points.end(), x) - all_points.begin() + 1;
	};
	int N = all_points.size();

	auto get_height = [&](ll point) {
		point = get_compressed(point);
		return query_max(1, 1, N, point);
	};

	auto update_height = [&](ll l, ll r, ll x) {
		l = get_compressed(l);
		r = get_compressed(r);
		update_max(1, 1, N, l, r, x);
	};

	auto get_sum_range = [&](ll l, ll r) {
		l = get_compressed(l);
		r = get_compressed(r);

		return query_sum(1, 1, N, l, r);
	};

	auto update_sum_range = [&](ll l, ll r, ll x) {
		l = get_compressed(l);
		r = get_compressed(r);

		update_sum(1, 1, N, l, r, x);
	};

	map<pii, ll> rect;

	auto inter = [](pii a, pii b) {
		if (a > b) swap(a, b);
		if (b.fi >= a.fi && b.se <= a.se) return true;
		if (a.fi >= b.fi && a.se <= b.se) return true;
		if (b.fi <= a.se) return true;
		return false;
	};

	auto qttinter = [](pii a, pii b) {
		if (a > b) swap(a, b);
		if (b.fi >= a.fi && b.se <= a.se) return b.se - b.fi;
		if (a.fi >= b.fi && a.se <= b.se) return a.se - a.fi;
		if (b.fi <= a.se) return a.se - b.fi;
		return 0ll;
	};

	auto merge = [](pii a, pii b) {
		pii ret;
		ret.fi = min(a.fi, b.fi);
		ret.se = max(a.se, b.se);
		return ret;
	};

	auto get_comprimento = [&](ll l, ll r) {
		ll maxi = 0;
		pii rt = {l, r};
		ll comp = r - l;
		auto it = rect.lower_bound({l, 0});
		if (it != rect.begin()) it--;

		vector<pii> toErase;
		for (int cnt = 0; it != rect.end(); it++) {
			if (inter(it->fi, rt)) {
				comp -= qttinter(it->fi, rt);
				toErase.push_back(it->fi);
				maxi = max(maxi, it->se);
				rt = merge(it->fi, rt);
			} else {
				cnt++;
				if (cnt >= 5) break;
			}
		}

		for (auto p : toErase)
			rect.erase(p);
		rect[rt] = maxi;
		return 2ll * comp;
	};

	auto is_left_border = [&](ll x) {
		auto it = rect.lower_bound({x, 0});
		return it != rect.end() && it->fi.fi == x;
	};

	auto is_right_border = [&](ll x) {
		auto it = rect.lower_bound({x, 0});
		if (it == rect.begin()) return false;
		return prev(it)->fi.se == x;
	};

	ll sum = 0, ans = 1;
	for (int i = 1; i <= n; i++) {
		ll L = l[i], R = l[i] + w[i];

		ll left_height = get_height(L);
		ll right_height = get_height(R);
		sum += h[i] - left_height;
		sum += h[i] - right_height;

		ll sum_range = get_sum_range(L + 1, R - 1);
		sum -= sum_range;

		update_sum_range(L + 1, R - 1, 0);

		ll sum_range_L = get_sum_range(L, L);
		if (is_right_border(L)) {
			sum -= sum_range_L;
			sum_range_L = 0;
		}

		update_sum_range(L, L, sum_range_L + h[i] - left_height);

		ll sum_range_R = get_sum_range(R, R);
		if (is_left_border(R)) {
			sum -= sum_range_R;
			sum_range_R = 0;
		}

		update_sum_range(R, R, sum_range_R + h[i] - right_height);

		update_height(L, R, h[i]);

		ll comprimento = get_comprimento(L, R);
		sum += comprimento;

		p[i] = (sum % MOD + MOD) % MOD;
		ans = ans * p[i] % MOD;
	}
	printf("Case #%d: %lld\n", __ntest__, ans);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}