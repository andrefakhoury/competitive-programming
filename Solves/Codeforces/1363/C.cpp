#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e3 + 5, INF = 0x3f3f3f3f;

int dist[MAXN];
int vis[MAXN];

inline void _solve_(int __ntest__) {
	int n, x; rd(n, x);

	vector<set<int>> edges(n+1);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].emplace(v);
		edges[v].emplace(u);
	}

	memset(dist, -1, sizeof dist);
	memset(vis, 0, sizeof vis);

	vector<int> q = {x};
	dist[x] = 0;
	while(q.size()) {
		int u = q.back();
		q.pop_back();
		for (int v : edges[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.eb(v);
			}
		}
	}

	for (int who = 0;; who ^= 1) {
		int nx = -1;
		for (int u = 1; u <= n; u++) {
			if (edges[u].size() <= 1u && !vis[u]) {
				if (nx == -1 or dist[u] == 0 or dist[u] > dist[nx]) {
					if (nx != -1 && dist[nx] == 0) continue;
					nx = u;
				}
			}
		}
		
		if (nx == x) {
			printf("%s\n", who ? "Ashish" : "Ayush");
			return;
		}

		for (int v : edges[nx]) {
			edges[v].erase(nx);
		}

		edges[nx].clear();
		vis[nx] = true;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}