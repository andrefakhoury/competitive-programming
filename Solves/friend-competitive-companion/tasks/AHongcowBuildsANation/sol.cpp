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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

vector<int> edges[MAXN];

int par[MAXN];
bool special[MAXN];
int sz[MAXN];
int qttEdges[MAXN];
bool leader[MAXN];

int find(int x) {
	if (par[x] == x) return x;
	return find(par[x]);
}

int main() {
	int n, m, k; rd(n, m, k);

	iota(par+1, par+n+1, 1);
	fill(sz+1, sz+n+1, 1);
	fill(leader+1, leader+n+1, true);

	for (int i = 0; i < k; i++) {
		int x; rd(x);
		special[x] = true;
	}

	auto merge = [&](int u, int v) {
		u = find(u); v = find(v);
		if (sz[u] > sz[v]) swap(u, v);
		qttEdges[v]++;
		if (u == v) return;
		par[u] = v;
		qttEdges[v] += qttEdges[u];
		sz[v] += sz[u];
		leader[u] = false;
		special[v] |= special[u];
	};

	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		merge(u, v);
	}

	int ans = 0;

	int maxSpecial = 0;
	int qttNot = 0;

	for (int i = 1; i <= n; i++) if (leader[i]) {
			ans += sz[i] * (sz[i] - 1) / 2 - qttEdges[i];
			if (special[i]) maxSpecial = max(maxSpecial, sz[i]);
			else {
				ans += qttNot * sz[i];
				qttNot += sz[i];
			}
		}

	ans += qttNot * maxSpecial;
	printf("%d\n", ans);
}