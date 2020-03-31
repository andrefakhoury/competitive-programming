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

const int MAXN = 500 + 5, INF = 0x3f3f3f3f;

int a[MAXN][MAXN];

int memo_bob[MAXN][MAXN];
int solve_bob(int n, int m) {
	memset(memo_bob, 0, sizeof memo_bob);
	memo_bob[0][1] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			memo_bob[i][j] = max(memo_bob[i-1][j]&a[i][j], memo_bob[i][j-1]&a[i][j]);
		}
	}
	return memo_bob[n][m];
}

int main() {
	int k; rd(k);

	int x = k | (1 << 17);
	int y = (1 << 17);

	printf("3 3\n");
	printf("%d %d %d\n", x, y, y);
	printf("%d %d %d\n", k, x, y);
	printf("%d %d %d\n", y, k, k);
}