#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
const int MAXN = 2e5 + 5;

struct UF_union {
	int par[MAXN], siz[MAXN];

	UF_union() { init(); }

	void init() {
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			siz[i] = 1;
		} 
	}

	int find(int x) {
		if (par[x] == x) return x;
		return find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);
		if (a == b) return;

		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		siz[b] += siz[a];
	}
};

void impossible() {
	printf("NO\n");
	exit(0);
}

int dir1[MAXN];

int main() {
	int n, m, d; scanf("%d%d%d", &n, &m, &d);
	UF_union uf;

	vector<int> con1;
	vector<pii> edges, ans, extra;

	while(m--) {
		int u, v; scanf("%d%d", &u, &v);

		if (u != 1 && v != 1) edges.pb(mp(u, v));
		else {
			con1.pb(u+v-1);
			dir1[u] = dir1[v] = true;
		}
	}

	if (con1.size() < d) impossible();

	for (pii e : edges) {
		int u = e.first, v = e.second;
		int a = uf.find(u), b = uf.find(v);

		if (dir1[a] and dir1[b]) extra.pb(mp(u, v));
		else if (!uf.same(u, v)) {
			ans.pb(mp(u, v));
			uf.merge(u, v);
		}
	}

	int qtt = 0;
	for (int v : con1) {
		if (!uf.same(1, v)) {
			ans.pb(mp(1, v));
			uf.merge(1, v);
			qtt++;
		}
	}

	if (qtt < d) {
		for (pii v : extra) {
			
		}
	}

	if (qtt < d) {
		for (int v : con1) {
			if (used[mp(1, v)]) continue;
			printf("Now using: %d %d\n", 1, v);
			printf("Ignoring: %d %d\n", v, uf.par[v]);

			ans.pb(mp(1, v));
			ignore[mp(v, uf.par[v])] = true;
			used[mp(1, v)] = true;
			qtt++;

			if (qtt == d) break;
		}
	}

	if (qtt < d or qtt > d) impossible();

	printf("YES\n");
	for (pii e : ans) {
		int u = e.first, v = e.second;

		if (ignore[mp(u, v)] or ignore[mp(v, u)]) continue;
		printf("%d %d\n", u, v);
	}
}