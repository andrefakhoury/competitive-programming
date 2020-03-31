/*
ID: fakhoury
LANG: C++11
TASK: moop
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

	inline void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u != v) {
			ans--;
			par[u] = v;
		}
	}
};

int main() {
#ifndef LOCAL_PC
	freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
#endif

    int n; rd(n);
    UF uf(n);

    vector<pii> a(n);
    for (pii& i : a) rd(i.fi, i.se);
    sort(a.begin(), a.end());

	set<pii> cur;
	for (int i = 0; i < n; i++) {
		int val = a[i].se;

		vector<set<pii>::iterator> toErase;
		for (auto it = cur.begin(); it != cur.end() && it->fi <= a[i].se; it++) {
			toErase.eb(it);
			uf.merge(i, it->se);
			val = min(val, it->fi);
		}

		for (auto p : toErase) cur.erase(p);
		cur.emplace(val, i);
	}

	printf("%d\n", uf.ans);
}