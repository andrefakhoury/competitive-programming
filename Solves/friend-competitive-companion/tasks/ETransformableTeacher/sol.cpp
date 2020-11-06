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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	int n, m; rd(n, m);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	sort(a.begin(), a.end());

	vector<ll> dif(n);
	for (int i = 0; i < n; i++) {
		if (i >= 2) dif[i] = dif[i-2];
		if (i >= 1) dif[i] += a[i] - a[i-1];
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i < m; i++) {
		int x; rd(x);

		auto go = [&](int j)->ll {
			ll cur = 0;
			if (j % 2 == 0) {
				cur = a[j] - x;
				if (j >= 1) cur += dif[j-1];
				cur += dif[n-1];
				cur -= dif[j];
			} else {
				cur = x - a[j-1];
				if (j >= 2) cur += dif[j-2];
				cur += dif[n-1];
				cur -= dif[j-1];
			}
			return cur;
		};

		int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
		ans = min(ans, go(idx));
	}

	printf("%lld\n", ans);
}