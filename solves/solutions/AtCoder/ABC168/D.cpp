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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

vector<int> edges[MAXN];
int ans[MAXN];
int level[MAXN];

inline void bfs() {
	queue<int> q;
	q.emplace(1);
	ans[1] = -1;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for (int v : edges[u]) {
			if (!ans[v]) {
				q.emplace(v);
				ans[v] = u;
			}
		}
	}

}

int main() {
	int n, m; rd(n, m);
	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	bfs();
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			puts("No");
			return 0;
		}
	}

	printf("Yes\n");
	for (int i = 2; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
}