#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct UF_rb {
	int par[MAXN], tam[MAXN];
	stack<pair<int, int> > old_par;
	stack<pair<int, int> > old_tam;

	void init() {
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			tam[i] = 1;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		return find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int x, int y) {
		int a = find(x);
		int b = find(y);
		
		if (tam[a] > tam[b]) swap(a, b);

		old_par.push(make_pair(a, par[a]));
		old_tam.push(make_pair(b, tam[b]));

		par[a] = par[b];
		tam[b] += tam[a];
	}

	void rollback() {
		if (old_par.size() == 0) return;
		if (old_tam.size() == 0) return;

		par[old_par.top().first] = old_par.top().second;
		tam[old_tam.top().first] = old_tam.top().second;

		old_par.pop();
		old_tam.pop();
	}
};

int main() {
	int n, q; cin >> n >> q;

	UF_rb uf;
	uf.init();

	while(q--) {
		char op; cin >> op;
		if (op == 'C') {
			int u, v; cin >> u >> v;
			printf("%c\n", uf.same(u, v) ? 'S' : 'N');
		} else {
			int u, v; cin >> u >> v;
			uf.merge(u, v);
		}
	}
}