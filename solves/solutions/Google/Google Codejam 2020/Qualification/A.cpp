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

inline void _solve_(int testCase) {
	int n; rd(n);
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rd(a[i][j]);
		}
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) sum += a[i][i];

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		set<int> cur;
		for (int j = 0; j < n; j++)
			cur.emplace(a[i][j]);
		ans1 += (int) cur.size() != n;
	}
	for (int j = 0; j < n; j++) {
		set<int> cur;
		for (int i = 0; i < n; i++)
			cur.emplace(a[i][j]);
		ans2 += (int) cur.size() != n;
	}

	printf("Case #%d: %lld %d %d\n", testCase, sum, ans1, ans2);
	
}

int main() {
	int __T__; rd(__T__);
	for (int i = 1; i <= __T__; i++) _solve_(i);
	return 0;
}