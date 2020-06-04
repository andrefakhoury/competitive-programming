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

const int MOD = 1e9 + 7;      

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int fpow(int x, int y) {
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

inline void _solve_(int __ntest__) {
	int n, p; rd(n, p);
	vector<int> a(n);
	for (int& i : a) rd(i);
	sort(a.begin(), a.end());

	if (p == 1) {
		printf("%d\n", n%2);
		return;
	}

	map<int, int> f;
	for (int i : a) f[i]++;

	int sum1 = 0;
	int sum2 = 0;

	while(f.size()) {
		auto v = *f.rbegin();

		if (v.se % 2 == 0) {
			int val = mul(v.se/2, fpow(p, v.fi));
			sum1 = add(sum1, val);
			sum2 = add(sum2, val);
			f.erase(v.fi);
		} else {

			vector<int> toer;
			bool ch = false;
			for (auto vv : f) {
				if (vv.se >= p) {
					ch = true;
					f[vv.fi+1] += vv.se / p;
					f[vv.fi] %= p;
				}
			}
			if (ch) continue;

			auto v1 = *f.rbegin();
			int val1 = mul(v1.se/2, fpow(p, v1.fi));
			for (auto v2 : f) if (v2.fi != v1.fi)
				val1 = add(val1, mul(v2.se, fpow(p, v2.fi)));

			sum1 = add(sum1, mul((v1.se+1)/2, fpow(p, v1.fi)));
			sum2 = add(sum2, val1);
			break;
		}
	}

	printf("%d\n", sub(sum1, sum2));
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}