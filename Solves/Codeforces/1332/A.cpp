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

inline void _solve_() {
	int a, b, c, d; rd(a, b, c, d);
	int x, y; rd(x, y);
	int x1, y1; rd(x1, y1);
	int x2, y2; rd(x2, y2);

	bool ans = true;
	if (x1 != x2) {
		if (a > b) {
			a -= b;
			ans &= (x - x1) >= a;
		} else {
			b -= a;
			ans &= (x2 - x) >= b;
		}
	} else {
		ans &= a == 0 && b == 0;
	}

	if (y1 != y2) {
		if (c > d) {
			c -= d;
			ans &= (y - y1) >= c;
		} else {
			d -= c;
			ans &= (y2 - y) >= d;

		}
	} else {
		ans &= c == 0 && d == 0;
	}

	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	int __T__; rd(__T__);
	while(__T__--) _solve_();
	return 0;
}