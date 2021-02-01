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

const int MAXN = 2e3 + 1;

vector<int> edges[MAXN];
int dist[MAXN][MAXN];

void bfs(int s) {
	mset(dist[s], 0x3f);
	dist[s][s] = 0;
	vector<int> qu = {s};
	for (int i = 0; i < (int) qu.size(); i++) {
		int u = qu[i];
		for (int v : edges[u]) if (dist[s][v] > dist[s][u] + 1) {
			dist[s][v] = dist[s][u] + 1;
			qu.push_back(v);
		}
	}
}

inline void run_test(int test_number) {
	int n, m, q; rd(n, m, q);
	for (int i = 0; i < m; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	for (int i = 1; i <= n; i++) bfs(i);

	vector<pii> bomb(q);
	for (int i = 0; i < q; i++) rd(bomb[i].fi, bomb[i].se);

	auto check = [&](int last_day) {
		for (int i = 1; i < q; i++) {
			int cur_d = dist[bomb[i-1].se][bomb[i].se];
			if (last_day + cur_d > bomb[i].fi) return false;
			last_day += cur_d;
		}
		return true;
	};

	int lo = 0, hi = bomb[0].fi, mi;
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(mi)) lo = mi;
		else hi = mi - 1;
	}

	if (!check(0)) {
		print(0);
		return;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dist[i][bomb[0].se] <= lo;
	}
	print(ans);
}

int main() {

#ifndef LOCAL_PC
	freopen("ysys.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}