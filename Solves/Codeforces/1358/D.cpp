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

const int MAXN = 4e5 + 5, INF = 0x3f3f3f3f;

ll a[MAXN];
ll sum[MAXN];
ll sum_ans[MAXN];

int main() {
	int n;
	ll x;
	rd(n, x);

	int N = n + n;

	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		a[i+n] = a[i];
	}

	auto get1 = [](ll x) {
		return x * (x + 1) / 2;
	};

	auto get = [&](ll l, ll r) {
		return get1(r) - get1(l-1);
	};

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] >= x)
			ans = max(ans, get(a[i]-x+1, a[i]));
		sum[i] = sum[i-1] + a[i];
		sum_ans[i] = sum_ans[i-1] + get(1, a[i]);
	}

	auto get_ans = [&](int l, int r) {
		ll ret = sum_ans[r-1] - sum_ans[l-1];
		ret += get(1, x - (sum[r-1] - sum[l-1]));
		return ret;
	};

	for (int i = 1; i <= n; i++) {
		if (sum[n] - sum[i-1] < x) continue;

		int lo = i, hi = i + n - 1, mi;
		while(lo < hi) {
			mi = (lo + hi) / 2;
			if (sum[mi] - sum[i-1] < x) lo = mi+1;
			else hi = mi;
		}

		ans = max(ans, get_ans(i, lo));
	}

	auto get_ans2 = [&](int l, int r) {
		ll ret = sum_ans[r] - sum_ans[l];
		// printf("[%d, %d] %lld -> ", l, r, ret);
		ret += get(a[l] - (x - (sum[r] - sum[l])) + 1, a[l]);
		// printf("%lld\n", ret);
		return ret;
	};

	// for (int i = 1; i <= N; i++) {
	// 	printf("%3lld ", sum[i]);
	// }
	// printf("\n");for (int i = 1; i <= N; i++) {
	// 	printf("%3lld ", a[i]);
	// }
	// printf("\n");

	for (int i = n+1; i <= N; i++) {
		int pos = upper_bound(sum+1, sum+N+1, sum[i]-x) - sum;
		// printf("%d, %d (%lld)\n", pos, i, ans);

		ans = max(ans, get_ans2(pos, i));
	}

	printf("%lld\n", ans);

}