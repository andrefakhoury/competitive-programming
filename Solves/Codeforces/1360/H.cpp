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
inline void _solve_(int __ntest__) {
	int n, m; rd(n, m);

	auto getval = [&](string s) {
		ll ret = 0;
		for (int i = m-1; i >= 0; i--) {
			if (s[i] == '1') ret += 1ll << (m - i - 1);
		}
		return ret;
	};

	vector<ll> vec;
	for (int i = 0; i < n; i++) {
		char aux[100];
		scanf(" %s", aux);
		vec.eb(getval(string(aux)));
	}
	sort(vec.begin(), vec.end());
	auto lft = [&](ll k) {
		return lower_bound(vec.begin(), vec.end(), k) - vec.begin();
	};
	auto rgt = [&](ll k) {
		return vec.end() - lower_bound(vec.begin(), vec.end(), k);
	};

	ll all = ((1ll << m) - n);
	for (ll b = max(0ll, (1ll << (m-1)) - 100); b < (1ll << m); b++) {
		if (binary_search(vec.begin(), vec.end(), b)) continue;
		ll L = lft(b), R = rgt(b);

		if (b-L + (all%2 == 0) >= all/2) {
			bitset<60> bts(b);
			for (int i = m-1; i >= 0; i--) {
				int cv = bts[i];
				printf("%d", cv);
			}
			printf("\n");
			return;
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}