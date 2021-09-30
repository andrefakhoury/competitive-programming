#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) do {cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; } while (0) 

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }


using ll = long long;
using ii = pair<int, int>;

using Gr = vector<vector<ii>>;

template<typename T = int>
constexpr T inf = 0x3f3f3f3f;

template<>
constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rng{seq};
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

struct Dinic {
	const long long flow_inf = 1e18;

	struct FlowEdge {
		int from, to;
		long long cap, flow = 0;
		FlowEdge(int from, int to, long long cap) : from(from), to(to), cap(cap) {}
	};

	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	vector<int> level, ptr;

	Dinic(int n) : adj(n), level(n), ptr(n) {}

	inline void add_edge(int from, int to, long long cap) {
		adj[from].push_back(edges.size());
		edges.emplace_back(from, to, cap);
		adj[to].push_back(edges.size());
		edges.emplace_back(to, from, 0);
	}

	inline bool bfs(int src, int snk) {
		fill(level.begin(), level.end(), -1);
		level[src] = 0;

		vector<int> q = {src};
		for (int i = 0; i < (int) q.size(); i++) {
			int u = q[i];
			for (int id : adj[u]) {
				if (edges[id].cap - edges[id].flow > 0 && level[edges[id].to] == -1) {
					level[edges[id].to] = level[u] + 1;
					q.push_back(edges[id].to);
				}
			}
		}

		return level[snk] != -1;
	}

	long long dfs(int u, int snk, long long pushed) {
		if (u == snk || pushed == 0) return pushed;		

		for (int& cid = ptr[u]; cid < (int) adj[u].size(); cid++) {
			int id = adj[u][cid];
			int v = edges[id].to;
			
			if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1) continue;
			long long tr = dfs(v, snk, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0) continue;

			edges[id].flow += tr;
			edges[id^1].flow -= tr;
			return tr;
		}

		return 0;
	}

	long long flow(int src, int snk) {
		long long f = 0;
		while (bfs(src, snk)) {
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(src, snk, flow_inf)) f += pushed;
		}
		return f;
	}
};


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	Dinic flow(n+2);

	for (int i = 1; i <= n; i++) {
		string op;
		cin >> op;

		if (op == "*") {
			int d;
			cin >> d;

			if (d == 1) {
				flow.add_edge(i, n+1, flow.flow_inf);
			}
			else flow.add_edge(i, d, flow.flow_inf);

			continue;
		}
		int k = stoi(op);

		map<int, int> cnt;
		while (k--) {
			int x;
			cin >> x;

			cnt[x]++;
		}

		for (auto [k, v] : cnt) {
			if (k == 1) flow.add_edge(i, n+1, v);
			else flow.add_edge(i, k, v);
		}
	}

	auto ans = flow.flow(1, n+1);

	if (ans == flow.flow_inf) {
		cout << "*\n";
	}
	else cout << ans+1 << "\n";
}

