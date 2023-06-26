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

template<class T> void DBG(T&& x) { cerr << x << ' '; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, k; rd(n, k);

	vector<int> cad(k), key(k);
	for (int i = 0; i < k; i++) rd(cad[i]), cad[i]--;
	for (int i = 0; i < k; i++) rd(key[i]), key[i]--;

	vector<vector<pii>> edges(n);
	for (int i = 1; i < n; i++) {
		int u, v, w; rd(u, v, w); u--, v--;
		edges[u].eb(v, w);
		edges[v].eb(u, w);
	}

	vector<int> new_ids(n, -1);
	for (int i = 0; i < k; i++) new_ids[cad[i]] = i;
	for (int i = 0; i < k; i++) new_ids[key[i]] = k + i;
	new_ids[0] = 2 * k;
	new_ids[n-1] = 2 * k + 1;

	const int N = 2 * k + 2;
	vector<vector<ll>> dist(N, vector<ll>(N));
	vector<vector<int>> needed(N, vector<int>(N));

	function<void(int, int, int, ll, int)> dfs = [&](int u, int p, int s, ll cur_dist, int cur_mask) {
		if (new_ids[u] != -1) {
			int idx = new_ids[u];
			if (idx < k) cur_mask |= 1 << idx;
			dist[s][idx] = cur_dist;
			needed[s][idx] = cur_mask;
		}
		for (auto [v, w]: edges[u]) if (v != p)
			dfs(v, u, s, cur_dist + w, cur_mask);
	};

	for (int i = 0; i < n; i++) if (new_ids[i] != -1)
		dfs(i, i, new_ids[i], 0, 0);

	const int NMASK = (1 << k) - 1;
	vector<vector<ll>> memo(N, vector<ll>(1 << k, -1));
	function<ll(int, int)> dfs_ans = [&](int u, int mask) {
		ll& ans = memo[u][mask];
		if (~ans) return ans;
		if (u == 2 * k + 1) return ans = 0;
		ans = 1e18;

		for (int v = 0; v <= 2 * k + 1; v++) if ((needed[u][v] & (NMASK ^ mask)) == 0) {
			int nmask = mask;
			if (v >= k && v < 2 * k) nmask |= 1 << (v - k);
			ans = min(ans, dist[u][v] + dfs_ans(v, nmask));
		}

		return ans;
	};

	ll ans = dfs_ans(2 * k, 0);
	if (ans == 1e18) print(-1);
	else print(ans);
}
