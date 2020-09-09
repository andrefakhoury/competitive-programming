#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
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

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

vector<int> read_vec(int n, int k) {
	vector<int> v(n);
	for (int i = 0; i < k; i++) {
		rd(v[i]);
	}

	ll a, b, c, d; rd(a, b, c, d);
	for (int i = k; i < n; i++) {
		v[i] = (a * v[i-2] + b * v[i-1] + c) % d;
	}

	return v;
}

inline void _solve_(int __ntest__) {
	printf("Case #%d: ", __ntest__);

	int n, k; rd(n, k);
	vector<int> s = read_vec(n, k);
	vector<int> x = read_vec(n, k);
	vector<int> y = read_vec(n, k);

	ll canLeave = 0, canJoin = 0, mustLeave = 0, mustJoin = 0;
	for (int i = 0; i < n; i++) {
		y[i] += x[i];

		if (s[i] >= x[i] && s[i] <= y[i]) {
			canJoin += y[i] - s[i];
			canLeave += s[i] - x[i];
		} else {
			if (s[i] < x[i]) {
				mustJoin += x[i] - s[i];
				canJoin += y[i] - x[i];
			} else if (y[i] < s[i]) {
				mustLeave += s[i] - y[i];
				canLeave += y[i] - x[i];
			} else {
				assert(0);
			}
		}
	}

	ll ans = min(mustLeave, mustJoin);
	mustLeave -= ans;
	mustJoin -= ans;
	if (mustLeave > canJoin or mustJoin > canLeave) {
		ans = -1;
	} else {
		ans += mustLeave + mustJoin;
	}

	printf("%lld\n", ans);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) {
		cerr << __i__ << endl;
		_solve_(__i__);
	}
	return 0;
}