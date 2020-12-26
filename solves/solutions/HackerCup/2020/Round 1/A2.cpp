#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
#define dbg(x) cerr << #x << " "; debug(x)
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

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

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
	rd(n, k);
	read(l); read(w); read(h);

	ll ans = 1;
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

	auto find_rec = [&](ll l, ll r, ll& sum, ll cur_hei) {
		ll maxi = 0;
		pii rt = {l, r};

		ll comp = r - l;

		auto it = rect.lower_bound({l, 0});
		if (it != rect.begin()) it--;

		vector<pii> toErase;

		int qtt = 0;
		for (int cnt = 0; it != rect.end(); it++) {
			if (inter(it->fi, rt)) {
				comp -= qttinter(it->fi, mk(l, r));
				qtt += 1;

				toErase.push_back(it->fi);
				maxi = max(maxi, it->se);
				rt = merge(it->fi, rt);
			} else {
				cnt++;
				if (cnt >= 5) break;
			}
		}

		sum += 2 * comp;
		if (qtt >= 1) sum -= 2ll * (qtt - 1) * cur_hei;
		else sum += 2ll * cur_hei;

		for (auto p : toErase)
			rect.erase(p);
		rect[rt] = maxi;
		return rt;
	};

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		pii r = find_rec(l[i], l[i] + w[i], sum, h[i]);
		ll H = max(rect[r], h[i]);
		rect[r] = H;

		sum = (sum % MOD + MOD) % MOD;
		p[i] = sum;
		ans = ans * p[i] % MOD;
	}

	printf("Case #%d: %lld\n", __ntest__, ans);
}

int main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}