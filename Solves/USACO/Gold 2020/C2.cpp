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

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;

int m;
vector<int> a;
bool comp[MAXN];

inline ll lcm(ll x, ll y) {
	return x / __gcd(x, y) * y % m;
}


int solve(int i, int n) {
	if (n < 0) return 0;
	if (i == (int) a.size()) return n;

	int x = solve(i+1, n);
	int y = solve(i+1, n - a[i]);

	int ans = max(x, lcm(y, a[i])) % m;
	printf("%d %d: %d\n", x, y, ans);

	return ans;
}

int main() {
#ifndef LOCAL_PC
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
#endif
	int n; rd(n);
	rd(m);

	a.pb(1);
	for (int i = 2; i <= n; i++) {
		if (comp[i]) continue;
		a.pb(i);
		for (int j = i + i; j <= n; j += i) comp[j] = true;
	}

	printf("%d\n", solve(0, n));
}