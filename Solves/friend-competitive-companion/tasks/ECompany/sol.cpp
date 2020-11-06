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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 1e5 + 5, LOG = 21, INF = 0x3f3f3f3f;
vector<int> edges[MAXN];
int par[MAXN][LOG];
int tin[MAXN], level[MAXN];
int curt = 0;

void dfs(int u, int p) {
	tin[u] = curt++;
	par[u][0] = p;
	for (int v : edges[u]) if (v != p) {
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}

struct Node {
	pii mn, mx, mn2, mx2; // <val, who>
	void merge(Node const& l, Node const& r) {
		if (l.mn < r.mn) {
			mn = l.mn;
			mn2 = min(l.mn2, r.mn);
		} else {
			mn = r.mn;
			mn2 = min(r.mn2, l.mn);
		}

		if (l.mx > r.mx) {
			mx = l.mx;
			mx2 = max(l.mx2, r.mx);
		} else {
			mx = r.mx;
			mx2 = max(r.mx2, l.mx);
		}
	}
} seg[4 * MAXN];

ostream& operator<<(ostream& out, pii const& p) {
	return out << "(" << p.fi << "," << p.se << ")";
}
ostream& operator<<(ostream& out, Node const& p) {
	return out << "[" << p.mn << "," << p.mn2 << " | " << p.mx << "," << p.mx2 << "]";
}

void build(int p, int i, int j) {
	cout <<
	if (i == j) {
		seg[p] = {mk(tin[i], i), mk(tin[i], i), mk(INF, -1), mk(-1, -1)};
	} else {
		int m = (i + j) / 2;
		build(p + p, i, m);
		build(p + p, m + 1, j);
		seg[p].merge(seg[p+p], seg[p+p+1]);
	}
}

Node query(int p, int i, int j, int l, int r) {
	Node ret = {mk(INF, -1), mk(-1, -1), mk(INF, -1), mk(-1, -1)};
	if (i > j || i > r || j < l) return ret;
	if (i >= l && j <= r) return seg[p];
	int m = (i + j) / 2;
	Node L = query(p + p, i, m, l, r);
	Node R = query(p + p + 1, m + 1, j, l, r);
	ret.merge(L, R);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		edges[u].pb(i);
		edges[i].pb(u);
	}

	dfs(1, 1);
	for (int b = 1; b < LOG; b++) {
		for (int u = 1; u <= n; u++) {
			par[u][b] = par[par[u][b-1]][b-1];
		}
	}

	auto lca = [&](int u, int v) {
		if (u < 1 || u > n) return INF;
		if (tin[u] > tin[v]) swap(u, v);
		for (int b = LOG-1; b >= 0; b--) {
			if (tin[par[v][b]] > tin[u]) v = par[v][b];
		}
		return level[par[v][0]];
	};

	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		cout << i << ": " << tin[i] << ": " << query(1, 1, n, i, i) << "\n";
	}

	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		if (l + 1 == r) {
			if (level[l] > level[r]) cout << r << " " << level[l] << "\n";
			else cout << l << " " << level[r] << "\n";
			continue;
		}

		Node cur = query(1, 1, n, l, r);
		cout << "between " << l << " and " << r << ": " << cur << "\n";

		pii ans = {INF, -1};
		ans = min(ans, mk(lca(cur.mn.se, cur.mx2.se), cur.mx.se));
		ans = min(ans, mk(lca(cur.mn2.se, cur.mx.se), cur.mn.se));
		cout << ans.se << " " << ans.fi << "\n";
	}
}