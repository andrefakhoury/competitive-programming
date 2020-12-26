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

const int MAXN = 1e4 + 1, INF = 0x3f3f3f3f;

bool h[MAXN][MAXN];

int main() {
	int g; rd(g);
	vector<pii> a(g);
	for (pii& x : a) rd(x.fi, x.se);

	int m; rd(m);
	while(m--) {
		int x, y, r; rd(x, y, r);
		for (int i = max(0, x - r); i <= min(10000, x + r); i++) {
			for (int j = max(0, y - r); j <= min(10000, y + r); j++) {
				if ((x - i) * (x - i) + (y - j) * (y - j) > r * r) continue;
				h[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (pii& x : a) ans += !h[x.fi][x.se];
	printf("%d\n", ans);
}