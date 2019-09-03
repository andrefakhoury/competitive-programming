#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e4 + 5;

pii edg[MAXN];

struct UF {
	int par[MAXN], siz[MAXN];

	void init(int n) {
		for (int i = 0; i <= n; i++) {
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

	int get(int u, int v) {
		return siz[find(u)] * siz[find(v)];
	}
};

int main() {
	UF uf;

	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		uf.init(n);

		set<int> all;
		for (int i = 1; i <= n - 1; i++) {
			int u, v; scanf("%d%d", &u, &v);

			edg[i] = {u, v};
			all.insert(i);
		}

		int q; scanf("%d", &q);
		vector<pair<char, int> > queries(q);

		for (int i = 0; i < q; i++) {
			char c; scanf(" %c", &c);
			int id = -1;

			if (c == 'R') scanf("%d", &id);
			queries[q-i-1] = {c, id};
			all.erase(id);
		}

		int cur = 0;
		for (int i : all) {
			cur += uf.get(edg[i].fi, edg[i].se);
			uf.merge(edg[i].fi, edg[i].se);
		}

		stack<int> ans;

		for (auto p : queries) {
			if (p.fi == 'R') {
				cur += uf.get(edg[p.se].fi, edg[p.se].se);
				uf.merge(edg[p.se].fi, edg[p.se].se);
			} else {
				ans.push(cur);
			}
		}

		while(ans.size()) {
			printf("%d\n", (n * (n - 1)) / 2 - ans.top());
			ans.pop();
		}

		printf("\n");
	}
}