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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

const int MAXN =  31622 + 1, INF = 0x3f3f3f3f;
const ll MAXK = 5e3, MAXX = 1e18;

inline ll get(int k) {
	ll ans = 1;
	while(ans*k <= MAXK) ans *= k;
	return ans;
}

inline ll ask(ll x) {
	cout << "? " << x << endl;
	ll k; cin >> k;
	return k;
}

inline ll cnt(ll x, ll k) {
	ll ans = 0;
	while(x && x%k == 0) {
		ans += 1;
		x /= k;
	}
	return ans;
}

bool cmp[MAXN];
ll val[MAXN];

int main() {
	vector<int> p;
	for (int i = 2; i < MAXN; i++) {
		if (cmp[i]) continue;
		for (int j = i + i; j < MAXN; j += i) cmp[j] = true;
		p.eb(i);
		val[i] = get(i);
	}

	int T; cin >> T;
	while(T--) {
		ll ans = 1;
		for (int it = 0, i = 0, j = (int) p.size()-1; it < 22; it++) {
			vector<int> cur;
			cur.eb(p[i++]);

			__int128 x = val[cur.back()];

			while(i <= j && x * val[p[i]] <= MAXX) {
				cur.eb(p[i]);
				x *= val[p[i]];
				i++;
			}

			while(j >= i && x * val[p[j]] <= MAXX) {
				cur.eb(p[j]);
				x *= val[p[j]];
				j--;
			}

			ll y = ask(ll(x));
			for (auto pp : cur)
				ans *= cnt(y, pp) + 1;
		}

		cout << "! " << 2 * ans << endl;
	}

}