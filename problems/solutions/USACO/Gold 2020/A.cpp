/*
ID: fakhoury
LANG: C++11
TASK: haircut
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

int a[MAXN];

ll bt[MAXN];
ll ans[MAXN];
inline void add(int x, int k) {
	x++;
	while(x < MAXN) {
		bt[x] += k;
		x += x&-x;
	}
}

inline ll get(int x) {
	x++;

	ll ret = 0;
	while(x > 0) {
		ret += bt[x];
		x -= x&-x;
	}
	return ret;
}

inline ll get(int l, int r) {
	return get(r) - get(l-1);
}

int main() {
#ifndef LOCAL_PC
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
#endif

	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]);

	for (int i = 1; i <= n; i++) {
		ans[a[i]+1] += get(a[i]+1, n);
		add(a[i], 1);
	}

	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cur += ans[i];
		printf("%lld\n", cur);
	}
}