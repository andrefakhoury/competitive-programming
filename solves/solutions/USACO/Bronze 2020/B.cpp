/*
ID: fakhoury
LANG: C++11
TASK: socdist2
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

struct UF {
	int par[MAXN], ans;

	UF(int n) {
		ans = n;
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) {
			ans--;
			par[u] = v;
		}
	}
};

int main() {
#ifndef LOCAL_PC
	freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
#endif

    int n; rd(n);
    vector<int> pos[2];

    for (int i = 0; i < n; i++) {
    	int x, y; rd(x, y);
    	pos[y].eb(x);
    }

    for (int i = 0; i < 2; i++) {
    	sort(pos[i].begin(), pos[i].end());
    }

    if (pos[0].empty()) {
    	printf("1\n");
    	return 0;
    }

    int mn = INT_MAX;
    for (int x : pos[0]) {
    	auto it = lower_bound(pos[1].begin(), pos[1].end(), x);

    	if (it != pos[1].end()) {
    		mn = min(mn, abs(x - *it));
    	}

    	if (it != pos[1].begin()) {
    		it--;
    		mn = min(mn, abs(x - *it));
    	}
    }

    UF uf(pos[1].size());
    for (int i = 1; i < (int)pos[1].size(); i++) {
    	if (pos[1][i] - pos[1][i-1] < mn) uf.merge(i-1, i);
    }

    printf("%d\n", uf.ans);
}