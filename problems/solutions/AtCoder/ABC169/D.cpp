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

int main() {
	ll n; rd(n);

	set<ll> st;
	st.emplace(1);

	vector<pair<ll, int>> divi;
	for (ll i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			divi.eb(i, 0);
			while(n%i == 0) {
				divi.back().second++;
				n /= i;
			}
		}
	}

	auto is_prime = [](ll n) {
		if (n == 1) return false;
		for (ll i = 2; i * i <= n; i++) {
			if (n%i == 0) return false;
		}
		return true;
	};

	if (is_prime(n)) divi.eb(n, 1);

	int ans = 0;
	for (auto [x, cnt] : divi) {
		ll lo = 1, hi = 1e6, mi;
		while(lo < hi) {
			mi = (lo + hi + 1) / 2;
			if (mi * (mi + 1) / 2 <= cnt) lo = mi;
			else hi = mi-1;
		}
		ans += lo;
	}

	printf("%d\n", ans);
}