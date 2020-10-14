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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;


struct TwoSat {
	vector<int> edges[MAXN];
	vector<int> reved[MAXN];

	inline int getPos(int i) { return i + i; }
	inline int getNeg(int i) { return i + i + 1; }
	inline void addEdge(int u, int v) {
		edges[u].push_back(v);
		reved[v].push_back(u);
	}

	void dfsOrder(int u, vector<int>& vis, vector<int>& order) {
		vis[u] = 1;
		for (int v : edges[u]) if (!vis[v])
				dfsOrder(v, vis, order);
		order.pb(u);
	}
	void dfsSCC(int u, int c, vector<int>& comp) {
		comp[u] = c;
		for (int v : reved[u]) if (!comp[v])
				dfsSCC(v, c, comp);
	}

	/** verify satisfiability. N is the number of VARIABLES on graph (qttVertices / 2) */
	inline bool isSat(int n, vector<int>& states) {
		states.assign(n, -1);
		vector<int> color(n + n);
		vector<int> order;
		for (int i = 0; i < n + n; i++) if (!color[i])
				dfsOrder(i, color, order);
		reverse(order.begin(), order.end());
		fill(color.begin(), color.end(), 0);
		for (int i = 0, c = 0; i < n + n; i++) if (!color[order[i]])
				dfsSCC(order[i], ++c, color);
		for (int i = 0; i < n + n; i += 2) {
			if (color[i] == color[i+1])
				return false;
		}

		for (int i = n + n - 1; i >= 0; i--) {
			if (states[order[i] / 2] == -1)
				states[order[i] / 2] = !(order[i]&1);
		}
		return true;
	}
} g;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		char c1, c2;
		int x1, x2;
		cin >> c1 >> x1 >> c2 >> x2;
		x1--, x2--;
		bool b1 = c1 == '+', b2 = c2 == '+';

		if (b1 && b2) {
			g.addEdge(g.getNeg(x1), g.getPos(x2));
			g.addEdge(g.getNeg(x2), g.getPos(x1));
		} else if (b1 && !b2) {
			g.addEdge(g.getNeg(x1), g.getNeg(x2));
			g.addEdge(g.getPos(x2), g.getPos(x1));
		} else if (!b1 && b2) {
			g.addEdge(g.getPos(x1), g.getNeg(x2));
			g.addEdge(g.getNeg(x2), g.getNeg(x1));
		} else {
			g.addEdge(g.getPos(x1), g.getNeg(x2));
			g.addEdge(g.getPos(x2), g.getNeg(x1));
		}
	}

	vector<int> states;
	if (!g.isSat(m, states)) cout << "IMPOSSIBLE";
	else for (int i : states) cout << (i ? '+' : '-') << " ";
	cout << "\n";
}
