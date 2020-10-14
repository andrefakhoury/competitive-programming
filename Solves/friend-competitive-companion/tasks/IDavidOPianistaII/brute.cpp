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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	int n; rd(n);
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
	}
	sort(a.begin(), a.end());

	ll ans = LLONG_MAX;
	do {
		bool valid = true;
		for (int i = 1; i < n; i++) valid &= a[i].fi >= a[i-1].fi;

		if (!valid) continue;
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && a[i].fi != a[i-1].fi) cur += abs(a[i].se - a[i-1].se);
		}
		ans = min(ans, cur);
	} while(next_permutation(a.begin(), a.end()));
	printf("%lld\n", ans);
}