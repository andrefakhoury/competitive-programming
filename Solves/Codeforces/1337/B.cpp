#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline bool g1(int x, int n, int m) {
	for (int i = 0; i < n; i++) {
		int y = x/2 + 10;
		if (x > y) x = y;
	}

	for (int i = 0; i < m; i++) {
		x -= 10;
	}

	return x <= 0;
}
inline bool g2(int x, int n, int m) {
	for (int i = 0; i < m; i++) {
		x -= 10;
	}

	for (int i = 0; i < n; i++) {
		int y = x/2 + 10;
		x = min(x, y);
	}

	return x <= 0;
}

inline void _solve_(int __ntest__) {
	int x, n, m; rd(x, n, m);
	printf("%s\n", g1(x, n, m) || g2(x, n, m) ? "YES" : "NO");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}