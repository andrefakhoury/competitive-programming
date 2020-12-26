/*
ID: fakhoury
LANG: C++11
TASK: cereal
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

struct Who {
	int u, lo, hi;
	Who() {}
	Who(int a, int b, int c) : u(a), lo(b), hi(c) {}
};

int main() {
#ifndef LOCAL_PC
	freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
#endif

    int n, m; rd(n, m);
    vector<pii> a(n);
    for (int i = 0; i < n; i++) rd(a[i].fi, a[i].se);


    vector<set<int>> ans(n+100);
	vector<Who> used(m+1);

	for (int i = 0; i <= m; i++) {
		used[i] = Who(-1, -1, -1);
	}

	for (int i = 0; i < n; i++) {
		int u = a[i].fi, v = a[i].se;

		int avu = min({i, used[u].u+1, used[u].hi+1});
		int avv = min({i, used[v].u+1, used[v].hi+1});

		if (avv < avu) { // vou usar V dps U
			ans[avv].emplace(i);

			used[v] = Who(i, avv, avu-1);
			used[u] = Who(i, avu, n-1);
		} else { // so vou usar o U
			ans[avu].emplace(i);
			used[u] = Who(i, avu, n-1);
		}
	}

	set<int> cur;
	for (int i = 0; i < n; i++) {
		while(cur.size() && *cur.begin() < i) cur.erase(cur.begin());
		for (auto x : ans[i]) cur.emplace(x);
		printf("%ld\n", cur.size());
	}
}