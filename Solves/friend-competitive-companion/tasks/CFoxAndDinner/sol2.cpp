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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

bool isComp[MAXN];
void init() {
	isComp[1] = true;
	for (int i = 2; i < MAXN; i++) if (!isComp[i]) {
		for (int j = i + i; j < MAXN; j += i) {
			isComp[j] = true;
		}
	}
}

int a[MAXN];

vector<int> edges[MAXN];

bool vis[MAXN];
int tin[MAXN];
int low[MAXN];
vector<int> cut_points;
int timer;

void dfs_cut(int u, int p = -1) {
	vis[u] = true;
	tin[u] = low[u] = timer++;

	int children = 0;
	for (int v : edges[u]) {
		if (vis[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs_cut(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u] && p != -1) {
				cut_points.pb(u);
			}
			children++;
		}
	}

	if (p == -1 && children > 1) {
		cut_points.pb(u);
	}
}

inline bool is_cut(int u) {
	return binary_search(cut_points.begin(), cut_points.end(), u);
}

vector<int> same_comp[MAXN];
int comp[MAXN];

void dfs_comp(int u, int c) {
	same_comp[u].pb(c);
	comp[u] = c;
	vis[u] = true;

	for (int v : edges[u]) if (!vis[v] && !is_cut(v)) {
		dfs_comp(v, c);
	}
}

vector<int> which_comp[MAXN];
vector<int> who_can[MAXN];

int main() {
	init();

	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!isComp[a[i] + a[j]]) {
				edges[i].pb(j);
				edges[j].pb(i);
			}
		}
	}

	mset(tin, -1);
	mset(low, -1);
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		dfs_cut(i);
	}

	sort(cut_points.begin(), cut_points.end());
	cut_points.erase(unique(cut_points.begin(), cut_points.end()), cut_points.end());

	mset(vis, 0);

	int n_comp = 0;
	for (int i = 1; i <= n; i++) if (!vis[i] && !is_cut(i)) {
		dfs_comp(i, ++n_comp);
	}

	for (int u : cut_points) {
		for (int v : edges[u]) if (comp[v]) {
			which_comp[u].pb(comp[v]);
		}
		sort(which_comp[u].begin(), which_comp[u].end());
		which_comp[u].erase(unique(which_comp[u].begin(), which_comp[u].end()), which_comp[u].end());
		for (int c : which_comp[u]) who_can[c].pb(u);
	}

	for (int c = 1; c <= n_comp; c++) {

	}


}
