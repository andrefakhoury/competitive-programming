// confia q o n*sqrt(n)*log(n)*10 passa

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
const int MAXL = 21;

vector<int> edges[MAXN];
vector<int> lives[MAXN];
vector<int> euler;
int ent[MAXN];
int sai[MAXN];
int level[MAXN];
int par[MAXN][MAXL];
int qtt[MAXN];

void dfs(int u, int p=-1) {
	ent[u] = euler.size();
	euler.eb(u);

	for (int v : edges[u]) if (v != p) {
		par[v][0] = u;
		level[v] = level[u] + 1;
		dfs(v, u);
	}

	sai[u] = euler.size();
	euler.eb(u);
}

inline int lca(int u, int v) {
	if (level[u] < level[v]) swap(u, v);
	for (int b = MAXL-1; ~b; b--)
		if (level[u] - (1 << b) >= level[v])
			u = par[u][b];

	if (u == v) return u;
	for (int b = MAXL-1; ~b; b--) {
		if (par[u][b] != par[v][b]) {
			u = par[u][b];
			v = par[v][b];
		}
	}

	return par[u][0];
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) return 0;
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct Query {
	int l, r, id;
	int64_t ord;

	Query() {}
	Query(int a, int b, int c) : l(a), r(b), id(c) {
		ord = gilbertOrder(l, r, 21, 0);
	}

	bool operator<(Query const& q) const {
		return ord < q.ord;
	}
};

vector<int> ans_query[MAXN];
bool present[MAXN];
int where[MAXN];
int current_in[MAXN];

inline void mo(vector<Query>& qry) {
	sort(qry.begin(), qry.end());
	set<int> cur;

	auto push_set = [&](int u) {
		for (int v : lives[u]) cur.emplace(v);
	};

	auto get = [&](int id, int x) {
		vector<int> toErase;
		for (auto v : cur) {
			if (!present[where[v]]) toErase.eb(v);
			else {
				ans_query[id].eb(v);
				if ((int) ans_query[id].size() == x) break;
			}
		}
		for (int x : toErase) {
			cur.erase(x);
			current_in[where[x]] = 0;
		}
	};

	auto go = [&](int id) {
		if (!present[euler[id]] && !current_in[euler[id]]) {
			push_set(euler[id]);
			current_in[euler[id]] = 1;
		}
		present[euler[id]] ^= 1;
	};

	int l = 1, r = 0;
	for (Query const& q : qry) {
		while (r < q.r) go(++r);
		while (r > q.r) go(r--);
		while (l < q.l) go(l++);
		while (l > q.l) go(--l);
		get(q.id, qtt[q.id/2]);
	}
}

inline void merge(vector<int>& x, vector<int>& y, int k) {
	for (int i : y) x.eb(i);
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	if ((int) x.size() > k) x.resize(k);
}

int main() {
	int n, m, q; rd(n, m, q);
	for (int i = 1; i < n; i++) {
		int u, v; rd(u, v);
		edges[u].eb(v);
		edges[v].eb(u);
	}

	dfs(1);
	for (int b = 1; b < MAXL; b++)
		for (int u = 1; u <= n; u++)
			par[u][b] = par[par[u][b-1]][b-1];

	for (int i = 1; i <= m; i++) {
		int x; rd(x);
		lives[x].eb(i);
		where[i] = x;
	}

	for (int i = 1; i <= n; i++) {
		sort(lives[i].begin(), lives[i].end());
		if (lives[i].size() > 10u) lives[i].resize(10);
	}

	vector<Query> qry(2 * q);
	for (int i = 0; i < q; i++) {
		int u, v, w; rd(u, v, w);
		int l = lca(u, v);
		qry[2*i] = {ent[l], ent[u], 2*i};
		qry[2*i+1] = {ent[l], ent[v], 2*i+1};
		qtt[i] = w;
	}

	mo(qry);
	for (int i = 0; i < 2*q; i += 2) {
		merge(ans_query[i], ans_query[i+1], qtt[i/2]);
		printf("%ld ", ans_query[i].size());
		for (int u : ans_query[i])
			printf("%d ", u);
		printf("\n");
	}
}