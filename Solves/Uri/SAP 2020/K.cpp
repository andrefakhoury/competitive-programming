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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<pii> edges[MAXN];
int ans[MAXN];

void dfs(int u, int mx, int p=-1) {
	ans[u] = mx;

	for (auto [v, w] : edges[u]) if (v != p) {
		dfs(v, min(mx, w), u);
	}
}

int main() {
	int n; rd(n);
	for (int i = 1; i < n; i++) {
		int u, v, w; rd(u, v, w);
		edges[u].eb(v, w);
		edges[v].eb(u, w);
	}

	dfs(n, INF);

	for (int i = 1; i < n; i++) {
		printf("%d", ans[i]);
		if (i+1 < n) printf(" ");
	}
	printf("\n");

}