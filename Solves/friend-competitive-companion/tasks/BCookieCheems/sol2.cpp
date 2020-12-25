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
ll memo[MAXN][21];
bool vis[MAXN];
int freq[MAXN];
int cnt[MAXN];
int c[MAXN];
int K;

int dfs(int u) {
	vis[u] = true;
	cnt[u] = freq[u];
	for (int v : edges[u]) if (!vis[v])
		cnt[u] += dfs(v);
	return cnt[u];
}
void solve(int u) {
	vis[u] = true;
	for (int v : edges[u]) if (!vis[v]) solve(v);

	for (int k = 0; k < cnt[u]; k++) memo[u][k] = 1e18;
	for (int x = cnt[u] - freq[u]; x > 0; x--) {

	}
	for (int k = freq[u] + 1; k <= K; k++) {
		memo[u][k] = min(memo[u][k])

	}
}

int main() {
	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	int T; rd(T);
	while(T--) {
		rd(K);
		mset(freq, 0);
		mset(memo, 0);
		mset(vis, 0);
		for (int i = 0, x; i < K; i++) rd(x), freq[x]++;
		for (int i = 1; i <= n; i++) rd(c[i]);
		dfs(1);
		mset(vis, 0);
		solve(1);
		printf("%lld\n", memo[1][K]);
	}
}
