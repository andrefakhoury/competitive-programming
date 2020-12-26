/*
ID: fakhoury
LANG: C++11
TASK: socdist
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

vector<pair<ll, ll>> a;

inline bool check(ll d, int n) {

	ll last = -d;
	for (int i = 0; n > 0 && i < (int)a.size(); i++) {
		while(n > 0 && a[i].se - last >= d) {
			n--;
			last = max(a[i].fi, last + d);
		}
	}

	return n <= 0;
}

int main() {
#ifndef LOCAL_PC
	freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
#endif

    int n, m; rd(n, m);
    a.resize(m);
    for (int i = 0; i < m; i++) {
    	rd(a[i].fi, a[i].se);
    }

    sort(a.begin(), a.end());
    ll lo = 1, hi = a.back().se + 100, mi;
    while(lo < hi) {
    	mi = (lo + hi + 1) / 2;
    	if (check(mi, n)) lo = mi;
    	else hi = mi-1;
    }

    printf("%lld\n", lo);	
}