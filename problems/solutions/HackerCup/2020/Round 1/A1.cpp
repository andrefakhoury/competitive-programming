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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, k, w;
ll l[MAXN];
ll h[MAXN];
ll p[MAXN];

inline void read(ll* v) {
	for (int i = 1; i <= k; i++) rd(v[i]);
	ll a, b, c, d; rd(a, b, c, d);
	for (int i = k + 1; i <= n; i++)
		v[i] = (a * v[i - 2] + b * v[i - 1] + c) % d + 1;
}

inline void _solve_(int __ntest__) {
	rd(n, k, w);
	read(l); read(h);

	ll ans = 1;
	set<pair<ll, ll>> mh;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i-1];
		if (l[i-1] + w < l[i]) { // novo retangulo
			p[i] += 2ll * h[i];
			p[i] += 2ll * w;
			mh.clear();
		} else { // retangulo ja existente
			while(mh.size() && mh.rbegin()->second < l[i])
				mh.erase(*mh.rbegin());

			ll M = mh.rbegin()->first;
			if (h[i] > M) {
				p[i] -= 2ll * M;
				p[i] += 2ll * h[i];
			}

			p[i] += 2ll * (l[i] - l[i-1]);
		}

		mh.emplace(h[i], l[i] + w);
		p[i] = (p[i] % MOD + MOD) % MOD;
		ans = ans * p[i] % MOD;
	}

	printf("Case #%d: %lld\n", __ntest__, ans);
}

int main() {
	l[0] = -INF;

	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}