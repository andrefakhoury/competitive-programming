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
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 1e5 + 5;
const ll INF = (ll) 1e15;

struct Edge {
	int u, v, p;
	Edge() {}
	Edge(int u, int v, int p) : u(u), v(v), p(p) {}
} all[MAXN];

int n;
vector<pii> edges[MAXN];
ll dist[MAXN];
int ndist[MAXN];

inline void dijkstra() {
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0ll, 1);
	for (int u = 2; u <= n; u++) dist[u] = INF;
	while(pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (-d > dist[u]) continue;

		for (auto [v, w] : edges[u]) {
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(-dist[v], v);
			}
		}
	}
}

vector<int> qu[MAXN];
bool vis[MAXN];
inline void update() {
	for (int u = 2; u <= n; u++) ndist[u] = n;
	mset(vis, 0);
	ndist[1] = 0;

	qu[0].push_back(1);
	for (int path = 0; path < n; path++) {
		for (int _ = 0; _ < (int) qu[path].size(); _++) {
			int u = qu[path][_];
			if (vis[u]) continue;
			vis[u] = true;

			for (auto [v, w] : edges[u]) {
				ll nd = dist[u] + ndist[u] + w - dist[v];
				if (ndist[v] > nd && nd < n) {
					ndist[v] = nd;
					qu[ndist[v]].push_back(v);
				}
			}
		}

		qu[path].clear();
	}

	for (int u = 1; u <= n; u++) {
		if (dist[u] < INF) dist[u] += ndist[u];
	}
}

int main() {
	int m, q; rd(n, m, q);
	for (int i = 1; i <= m; i++) {
		int u, v, w; rd(u, v, w);
		all[i] = {u, v, (int) edges[u].size()};
		edges[u].eb(v, w);
	}

	dijkstra();
	for (int i = 1; i <= q; i++) {
		int op; rd(op);
		if (op == 1) {
			int u; rd(u);
			printf("%lld\n", dist[u] < INF ? dist[u] : -1);
		} else {
			int k; rd(k);
			for (int j = 1; j <= k; j++) {
				int v; rd(v);
				edges[all[v].u][all[v].p].second++;
			}
			update();
		}
	}

	return 0;
}
