#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 5;
const int MAXL = 21;

vector<int> edges[MAXN];
int dist[MAXN];
int disabled[MAXN];

void dfs_dist(int u, int d, int p) {
	dist[u] = d;
	for (int v : edges[u])
		if (v != p) dfs_dist(v, d+1, u);
}

inline int longest(int u, int n) {
	dfs_dist(u, 0, u);
	int b = u;
	for (int i = 1; i <= n; i++) if (dist[i] > dist[b]) b = i;
	return b;
}

inline int ask(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int x; scanf("%d", &x);
	if (x == -1) exit(0);
	return x;
}

inline void guess(int u) {
	printf("! %d\n", u);
	fflush(stdout);
	exit(0);
}

set<int> lf;
int leaf(int u, int p) {
	for (int v : edges[u])
		if (v != p) return leaf(v, u);
	return u;
}

bool dfs_del(int u, int dest, int lc, int prev) {
	if (u == dest) {
		if (u != lc) freq.erase(u);
		return true;
	}

	bool cur = false;
	for (int v : edges[u]) {
		if (v == prev) continue;
		bool at = dfs_del(v, dest, lc, u);
		if (at && u != lc) freq.erase(u);
		cur |= at;
	}

	return cur;
}

inline void delete_middle(int st, int en, int lc) {
	dfs_del(st, en, lc, -1);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edges[u].pb(v); edges[v].pb(u);
	}

	for (int i = 1; i <= n; i++) leaf(i, i);

	vector<int> v;
	for (int xx : lf) v.eb(xx);
	shuffle(v.begin(), v.end(), rng);
	
	vector<int> vv;
	for (int i = 1; i <= n; i++) vv.eb(i);
	shuffle(vv.begin(), vv.end(), rng);
	for (auto p : vv) v.eb(p);

	for (int i = 0, qtt = 0; qtt < n/2 && i < (int)v.size(); i++) {
		int _u = v[i];
		int _v = longest(v[i], n);
		if (_u > _v) swap(_u, _v);

		if (perg.count({_u, _v})) continue;
		qtt++;

		int _l = ask(_u, _v);
		freq[_l]++;
		perg[{_u, _v}] = _l;
	}

	for (auto p : perg)
		delete_middle(p.fi.fi, p.fi.se, p.se);

	guess(best(freq));
	return 0;
}