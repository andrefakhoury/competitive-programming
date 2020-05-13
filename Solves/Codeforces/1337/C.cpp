#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int qtt[MAXN], sz[MAXN];
vector<int> edges[MAXN];

int init(int u, int p = -1, int q = 0) {
	sz[u] = 1;
	qtt[u] = q;
	for (int v : edges[u]) if (v != p)
		sz[u] += init(v, u, q + 1);
	return sz[u];
}

bool chosen[MAXN];

ll solve(int u, int p = -1, int q = 0) {
	ll ret = 0;
	if (chosen[u]) ret += q;
	else q++;

	for (int v : edges[u]) if (v != p) {
		ret += solve(v, u, q);
	}

	return ret;
}

int main() {
	int n, k; rd(n, k);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	init(1);

	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		pq.emplace(qtt[i] - sz[i], i);
	}

	for (int i = 1; i <= k; i++) {
		chosen[pq.top().se] = true;
		pq.pop();
	}

	printf("%lld\n", solve(1));

}