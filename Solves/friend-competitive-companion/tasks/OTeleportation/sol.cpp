#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];

set<int> vertices[100];
int dist[MAXN];

int main() {
	int n, m, k; rd(n, m, k);
	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
//		edges[v].pb(u);
	}

	for (int i = 1; i <= n; i++) vertices[i%k].insert(i);
	mset(dist, -1);

	auto tira = [&](int v) {
		vertices[v%k].erase(v);
	};

	int S, T; rd(S, T);
	vector<int> queue = {S};
	dist[S] = 0;
	tira(S);
	for (int i = 0; i < (int) queue.size(); i++) {
		int u = queue[i];
		for (int v : edges[u]) if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			tira(v);
			queue.pb(v);
		}

		for (int v : vertices[u%k]) if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			queue.pb(v);
		}
		vertices[u%k].clear();
	}

	printf("%d\n", dist[T]);
}
