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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	int n, a, r, m;
	rd(n, a, r, m);

	vector<int> h(n);
	for (int& i : h) rd(i);
	sort(h.begin(), h.end());
	
	vector<ll> sum(n);
	for (int i = 0; i < n; i++) {
		sum[i] = (i ? sum[i-1] : 0) + h[i];
	}

	vector<int> allIdx;
	for (int i = 0; i < n; i++) allIdx.eb(h[i]);
	for (int i = 0; i < n; i++) allIdx.eb((sum[n-1]+i)/n);
	for (int i = 0; i < n; i++) {
		allIdx.eb((h[0] + h[i]) / 2);
		allIdx.eb((h[0] + h[i] + 1) / 2);
	}
	for (int i = 0; i < n; i++) {
		allIdx.eb((h[n-1] + h[i]) / 2);
		allIdx.eb((h[n-1] + h[i] + 1) / 2);
	}

	sort(allIdx.begin(), allIdx.end());
	allIdx.erase(unique(allIdx.begin(), allIdx.end()), allIdx.end());

	ll ans = LLONG_MAX;
	for (int i : allIdx) {
		ll toAdd = 0, toRem = 0;

		auto it1 = upper_bound(h.begin(), h.end(), i);
		if (it1 != h.begin()) {
			it1--;

			toAdd = (it1-h.begin()+1) * i - sum[it1-h.begin()];
		}

		auto it2 = upper_bound(h.begin(), h.end(), i);
		if (it2 != h.end()) {
			toRem = (sum[n-1] - (it2 == h.begin() ? 0 : sum[it2-h.begin()-1])) - (h.end() - it2) * i;
		}

		ll cur = 0;
		if (m <= a + r) {
			ll qtt = min(toAdd, toRem);
			cur += qtt * m;
			toAdd -= qtt;
			toRem -= qtt;
		}

		cur += toAdd * a;
		cur += toRem * r;

		// printf("[%d]: %lld\n", i, cur);

		ans = min(ans, cur);
	}

	printf("%lld\n", ans);
}