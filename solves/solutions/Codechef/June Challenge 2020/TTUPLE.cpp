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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline bool can1(vector<pii> v) {
	vector<ll> a, b;
	for (auto p : v) if (p.fi != p.se) {
		a.eb(p.fi);
		b.eb(p.se);
	}

	bool ok[2] = {1, 1};
	for (int i = 0; i+1 < (int) a.size(); i++) {
		ok[0] &= (b[i] - a[i]) == (b[i+1] - a[i+1]);
		ok[1] &= (a[i] != 0) && (a[i+1] != 0) && (b[i]%a[i] == 0) && (b[i+1]%a[i+1] == 0) && (b[i]/a[i] == b[i+1]/a[i+1]);
	}

	return ok[0] or ok[1];
}

inline bool mult1(vector<pii> v) {
	for (int i = 0; i < 3; i++) if (v[i].fi && (v[i].se % v[i].fi) == 0) {
		ll K = v[i].se / v[i].fi;
		if (can1({mk(v[0].fi * K, v[0].se), mk(v[1].fi * K, v[1].se), mk(v[2].fi * K, v[2].se)})) return true;
		if (can1({mk(v[0].fi * K, v[0].se), mk(v[1].fi * K, v[1].se), mk(v[2].fi, v[2].se)})) return true;
		if (can1({mk(v[0].fi * K, v[0].se), mk(v[1].fi, v[1].se), mk(v[2].fi * K, v[2].se)})) return true;
		ll old = v[i].fi;
		v[i].fi = v[i].se;
		if (can1(v)) return true;
		v[i].fi = old;
	}
	return false;
}

inline bool mult2(vector<pii> v, vector<int>&& pos) {
	ll D = 0;
	for (int i = 0; i < 3; i++) if (pos[i] == 0)
		D = v[i].se - v[i].fi;

	for (int i = 0; i < 3; i++) if (pos[i] == 1) {
		if (v[i].fi == 0) return false;
		if ((v[i].se - D) % v[i].fi == 0) {
			ll K = (v[i].se - D) / v[i].fi;
			vector<pii> v2;
			for (int j = 0; j < 3; j++) {
				if (pos[j]) v2.eb(v[j].fi * K, v[j].se);
				else v2.eb(v[j].fi, v[j].se);
			}
			if (can1(v2)) return true;
		}
	}

	return false;
}

inline bool mult3(vector<pii> v) {
	ll x = v[0].se;
	ll y = v[1].se;
	ll a = v[0].fi;
	ll b = v[1].fi;

	if (a == b) return false;
	if ((x - y) % (a - b) != 0) return false;
	ll K = (x - y) / (a - b);
	return can1({mk(v[0].fi * K, v[0].se), mk(v[1].fi * K, v[1].se), mk(v[2].fi * K, v[2].se)});
}

inline bool smul1(vector<pii> v) {
	for (int i = 0; i < 3; i++) {
		if (v[i].fi && v[i].se % v[i].fi == 0) {
			ll K = v[i].se / v[i].fi;
			bool ok = true;
			set<ll> pos;
			for (int j = 0; ok && j < 3; j++) {
				if (K == 0 or v[j].se % K != 0) ok = false;
				else pos.emplace(v[j].se / K - v[j].fi);
			}
			pos.erase(0ll);
			if (ok && pos.size() <= 1u) return true;
		}
	}
	return false;
}

inline bool trym(vector<pii> v, ll K) {
	set<ll> pos;
	for (int i = 0; i < 3; i++) {
		if (v[i].se % K != 0) return false;
		pos.emplace(v[i].se / K - v[i].fi);
	}
	pos.erase(0ll);
	return pos.size() <= 1u;
}

inline bool smul2(vector<pii> v) {
	ll G = 0;
	for (int i = 0; i < 3; i++) {
		if (v[i].se == 0) return false;
		G = gcd(G, v[i].se);
	}

	G = abs(G);
	for (ll i = 1; i * i <= G; i++) {
		if (G%i == 0) {
			if (trym(v, i)) return true;
			if (trym(v, -i)) return true;
			if (trym(v, G/i)) return true;
			if (trym(v, -G/i)) return true;
		}
	}

	return false;
}

inline bool smul3(vector<pii> v, vector<int>&& pos) {
	ll G = 0;
	for (int i = 0; i < 3; i++) if (pos[i]) {
		if (v[i].se == 0) return false;
		G = gcd(G, v[i].se);
	}

	G = abs(G);
	for (ll i = 1; i * i <= G; i++) {
		if (G%i == 0) {
			for (ll p : vector<ll>{i, -i, G/i, -G/i}) {
				vector<pii> v2;
				for (int j = 0; j < 3; j++) {
					if (pos[j]) v2.eb(v[j].fi, v[j].se / p);
					else v2.eb(v[j].fi, v[j].se);
				}
				if (can1(v2)) return true;
			}
		}
	}

	return false;
}

inline bool can(vector<pii> const& v) {
	if (can1({v[0], v[1]})) return true;
	if (can1({v[0], v[2]})) return true;
	if (can1({v[1], v[2]})) return true;

	{ // Soma Soma
		vector<ll> d(3);
		for (int i = 0; i < 3; i++) d[i] = v[i].se - v[i].fi;
		if (d[0] == d[1]) return true;
		if (d[0] == d[2]) return true;
		if (d[1] == d[2]) return true;
		if (d[0] + d[1] == d[2]) return true;
		if (d[0] + d[2] == d[1]) return true;
		if (d[1] + d[2] == d[0]) return true;
	}
	{ // Mult Mult
		bool can = true;
		vector<ll> k(3);
		for (int i = 0; i < 3; i++) if (v[i].fi && v[i].se % v[i].fi == 0) {
			k[i] = v[i].se / v[i].fi;
		} else can = false;
		if (can && k[0] == k[1]) return true;
		if (can && k[0] == k[2]) return true;
		if (can && k[1] == k[2]) return true;
		if (can && k[0] * k[1] == k[2]) return true;
		if (can && k[0] * k[2] == k[1]) return true;
		if (can && k[1] * k[2] == k[0]) return true;
	}
	{ // Mult Soma
		if (mult1(v)) return true;
		if (mult2(v, {1, 1, 0})) return true;
		if (mult2(v, {1, 0, 1})) return true;
		if (mult2(v, {0, 1, 1})) return true;
		if (mult3(v)) return true;
	}
	{ // Soma Mult
		if (smul1(v)) return true;
		if (smul2(v)) return true;
		if (smul3(v, {1, 0, 0})) return true;
		if (smul3(v, {0, 1, 0})) return true;
		if (smul3(v, {0, 0, 1})) return true;
		if (smul3(v, {1, 1, 0})) return true;
		if (smul3(v, {1, 0, 1})) return true;
		if (smul3(v, {0, 1, 1})) return true;
		if (smul3(v, {1, 1, 1})) return true;
	}

	return false;
}

inline int _solve_(int __ntest__) {
	int x[3]; rd(x[0], x[1], x[2]);
	int y[3]; rd(y[0], y[1], y[2]);
	vector<pii> v;

	for (int i = 0; i < 3; i++)
		if (x[i] != y[i]) v.eb(x[i], y[i]);

	if (v.empty()) return 0;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (can1(v)) return 1;
	if (v.size() == 2u) return 2;
	if (can(v)) return 2;
	return 3;
}

int32_t main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) {
		int ans = _solve_(__i__);
		printf("%d\n", ans);
	}
	return 0;
}