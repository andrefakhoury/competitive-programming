#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 4e5 + 10, INF = 0x3f3f3f3f;

int n, K;
int a[MAXN];
int bt[MAXN];

inline void update(int i, int k) {
	while(i <= 2*K + 5) {
		bt[i] += k;
		i += i&-i;
	}
}

inline void update(int l, int r, int k) {
	if (l > r) return;
	update(l, k);
	update(r+1, -k);
}

inline int query(int i) {
	int ret = 0;
	while(i) {
		ret += bt[i];
		i -= i&-i;
	}
	return ret;
}

inline void _solve_(int __ntest__) {
	int k; rd(n, k);
	K = k;
	for (int i = 1; i <= n; i++) rd(a[i]);

	for (int i = 1, j = n; i < j; i++, j--) {
		int zr = a[i] + a[j];
		pii mn = mk(min(a[i], a[j]) + 1, max(a[i], a[j]) + k);
		pii mx = mk(2, 2 * k);

		update(mn.fi, zr-1, 1);
		update(zr+1, mn.se, 1);
		update(mx.fi, mn.fi-1, 2);
		update(mn.se+1, mx.se, 2);
	}

	int ans = INT_MAX;
	for (int i = 2; i <= 2*k; i++) {
		ans = min(ans, query(i));
	}

	printf("%d\n", ans);

	for (int i = 1; i <= 2 * k + 5; i++) bt[i] = 0;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}