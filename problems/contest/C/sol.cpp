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

const int MAXN = 1e5, LOG = 31;
int n, a[MAXN];
set<int> active[31];
set<int> allx;

int vis[MAXN];

vector<int> ans;

void solve(int u) {
	vis[u] = 1;
	ans.push_back(a[u]);
	allx.erase(u);
	for (int b = 0; b < LOG; b++) if (a[u] & (1 << b)) {
		active[b].erase(u);
	}
	int mini = n;
	for (int i = 0; i < LOG; i++) if (a[u] & (1 << i)) {
		if (active[i].size()) {
			mini = min(mini, *active[i].begin());
		}
	}
	if (mini != n) solve(mini);
	if (allx.size()) solve(*allx.begin());
}


inline void run_test(int test_number) {
	rd(n);
	for (int i = 0; i < n; i++) {
		rd(a[i]);
		for (int b = 0; b < LOG; b++) if (a[i] & (1 << b)) {
			active[b].insert(i);
		}
		allx.insert(i);
	}

	solve(0);

	for (int i : ans) cout << i << " ";
	cout << "\n";


}

int main() {

#ifndef LOCAL_PC
	freopen("sorting.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}