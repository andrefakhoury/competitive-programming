#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const int BKSZ = 333;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

set<int> adj[MAXN];

struct Query {
	int id, l, r;
	Query() {}
	Query(int id, int l, int r) {
		this->id = id;
		this->l = l;
		this->r = r;
	}

	bool operator< (const Query& b) const {
		if (l/BKSZ == b.l/BKSZ) return r < b.r;
		return l/BKSZ < b.l/BKSZ;
	}
};

vector<pair<int, int> > edges;

struct Mo {
	int q, n;
	vector<Query> qry;
	vector<int> color;

	Mo() {}
	Mo(int n) {
		this->n = n;
		this->q = 0;
	}

	inline void addQuery(int l, int r) {
		qry.push_back(Query(q++, l, r));
	}

	inline void add(int id) {
		adj[edges[id].fi].insert(edges[id].se);
		adj[edges[id].se].insert(edges[id].fi);
	}

	inline void remove(int id) {
		if (!adj[edges[id].fi].count(edges[id].se)) return;
		adj[edges[id].fi].erase(edges[id].se);
		adj[edges[id].se].erase(edges[id].fi);
	}

	inline bool dfs(int u, int c) {
		color[u] = c;
		for (int v : adj[u]) {
			if (color[v] && color[v] == c) return false;
			if (!color[v] && !dfs(v, 3-c)) return false;
		}
		return true;
	}

	inline bool getAns() {
		color = vector<int>(n+1);

		for (int i = 1; i <= n; i++)
			if (!color[i] && !dfs(i, 1)) return false;
		return true; 
	}

	void MoAlgorithm() { //O( (n+q) * sqrt(n) * f)
		bitset<MAXN> ans;
		sort(qry.begin(), qry.end());

		int l = 0, r = -1;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (r < qry[i].r) add(++r);
			while (r > qry[i].r) remove(r--);
			while (l < qry[i].l) remove(l++);
			while (l > qry[i].l) add(--l);
			ans[qry[i].id] = getAns();
		}

		for (int i = 0; i < q; i++)
			printf("%sossible\n", ans[i] ? "P" : "Imp");
	}
};

int main() {
	int n, m, q; scanf("%d%d%d", &n, &m, &q);

	edges.resize(m);
	for (auto& p : edges) scanf("%d%d", &p.fi, &p.se);

	Mo mo(n);
	for (int i = 0; i < q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		mo.addQuery(l-1, r-1);
	}

	mo.MoAlgorithm();

	return 0;
}