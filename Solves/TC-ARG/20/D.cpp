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
	char c, neg = 0; while(isspace(c = getchar()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

vector<pii> edges[MAXN];
map<pii, int> memo;

int dfs(int u, int last) {
	if (memo.count(mk(u, last))) return memo[{u, last}];
	memo[{u, last}] = 0;

	int cur = 0;
	for (auto [v, w] : edges[u]) if (w > last)
		cur = max(cur, 1 + dfs(v, w));

	return memo[{u, last}] = cur;
}

int main() {
	int n, m; rd(n, m);
	for (int i = 0; i < m; i++) {
		int u, v, w; rd(u, v, w);
		edges[u].eb(v, w);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dfs(i, 0));
	printf("%d\n", ans);
}