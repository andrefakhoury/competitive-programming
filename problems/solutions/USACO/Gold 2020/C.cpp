/*
ID: fakhoury
LANG: C++11
TASK: exercise
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int MOD;

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

inline int inv(int x) {
	int y = MOD-2;
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

inline ll lcm(ll x, ll y) {
	return x / __gcd(x, y) * y;
}

int comp[MAXN];

inline int get(int l, int r, vector<int>& sum) {
	return sum[r] - sum[l-1];
}

int main() {
#ifndef LOCAL_PC
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
#endif
	int n; rd(n, MOD);

	if (n <= 100) {
		vector<int> primes;
		for (int i = 2; i <= n; i++) {
			if (comp[i]) continue;
			primes.pb(i);
			for (int j = i+i; j <= n; j += i)
				comp[j] = true;
		}

		set<ll> all;
		int sz = primes.size();
		for (int i = 0; i < sz; i++) {
			ll cur = primes[i];
			while(cur <= n) {
				cur *= primes[i];
				if (cur > n) break;
				primes.pb(cur);
			}
		}

		sort(primes.begin(), primes.end());
		set<pair<int, ll>> aa;

		for (int u : primes) aa.emplace(u, u);

		for (int u : primes) {
			vector<pair<int, ll>> toEmplace;
			for (auto p : aa) {
				if (p.fi + u <= n) {
					if (lcm(p.se, u) != p.se)
						toEmplace.emplace_back(p.fi+u, lcm(p.se, u));
				}
			}

			for (auto p : toEmplace) {
				aa.emplace(p);
				all.emplace(p.se);
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) all.emplace(i);
		for (auto x : all) ans = add(ans, x%MOD);
		printf("%d\n", ans);
	} else {
		vector<int> primes;
		for (int i = 2; i <= n; i++) {
			if (comp[i]) continue;
			primes.pb(i);
			for (int j = i+i; j <= n; j += i)
				comp[j] = true;
		}

		set<ll> all;
		int sz = primes.size();
		for (int i = 0; i < sz; i++) {
			ll cur = primes[i];
			while(cur <= n) {
				cur *= primes[i];
				if (cur > n) break;
				primes.pb(cur);
			}
		}

		sort(primes.begin(), primes.end());
		set<pair<int, ll>> aa;

		for (int u : primes) aa.emplace(u, u);

		for (int u : primes) {
			vector<pair<int, ll>> toEmplace;
			for (auto p : aa) {
				if (p.fi + u <= n) {
					if (lcm(p.se, u) != p.se && !all.count(lcm(p.se, u))) {
						toEmplace.emplace_back(p.fi+u, lcm(p.se, u));
					}
				} else break;
			}

			for (auto p : toEmplace) {
				aa.emplace(p);
				all.emplace(p.se);
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) all.emplace(i);
		for (auto x : all) ans = add(ans, x%MOD);
		printf("%d\n", ans);		
	}
}
