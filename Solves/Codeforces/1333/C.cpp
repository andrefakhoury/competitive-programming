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

int a[MAXN];
ll acc[MAXN];

int main() {
	int n; rd(n);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		acc[i] = acc[i-1] + a[i];
	}

	ll ans = 0;

	map<ll, int> pos;

	int last = n;
	for (int i = n; i >= 1; i--) {
		pos[acc[i]] = i;
		int id = pos[acc[i] - a[i]];
		if (id) last = min(last, id - 1);

		ans += last - i + 1;
	}

	printf("%lld\n", ans);
}