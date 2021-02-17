#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

const int N = 505;
const int X = 1e6 + 6;

int n, m, q;
int a[N][N];
vector<pii> pos[X];

int par[N*N], sz[N*N], tim[N*N];

int get(int i, int j) {
	return i * m + j;
}
int find(int x, int t) {
	if (par[x] == x || tim[x] > t) return x;
	return find(par[x], t);
}
void merge(int u, int v, int t) {
	u = find(u, t);
	v = find(v, t);
	if (u == v) return;
	if (sz[u] > sz[v]) swap(u, v);
	par[u] = v;
	tim[u] = t;
	sz[v] += sz[u];
}
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
void add(int i1, int j1, int i2, int j2, int x) {
	if (valid(i1, j1) && valid(i2, j2)) merge(get(i1, j1), get(i2, j2), x);
}
int solve(int i1, int j1, int i2, int j2) {
	int u = get(i1, j1);
	int v = get(i2, j2);

	int lo = max(a[i1][j1], a[i2][j2]), hi = X-1, mi;

	while(lo < hi) {
		mi = (lo + hi) / 2;
		if (find(u, mi) == find(v, mi)) hi = mi;
		else lo = mi + 1;
	}
	return lo;
}

inline void run_test(int test_number) {
	rd(n, m, q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rd(a[i][j]);
			pos[a[i][j]].eb(i, j);
			tim[get(i, j)] = a[i][j];
		}
	}

	for (int i = 0; i < N * N; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	const int dx[4] = {1, -1, 0, 0};
	const int dy[4] = {0, 0, 1, -1};

	for (int x = 0; x < X; x++) {
		for (auto p : pos[x]) {
			int i = p.fi, j = p.se;
			for (int k = 0; k < 4; k++) {
				int i2 = i + dx[k], j2 = j + dy[k];
				if (valid(i2, j2) && a[i2][j2] <= x)
					add(i, j, i2, j2, x);
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int i1, j1, i2, j2; rd(i1, j1, i2, j2);
		print(solve(i1-1, j1-1, i2-1, j2-1));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}