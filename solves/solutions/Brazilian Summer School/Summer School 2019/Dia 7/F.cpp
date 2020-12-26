#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;
struct UF {
	int par[MAXN], tam[MAXN], n;

	UF() {}
	UF(int n) {
		this->n = n;
		init();
	}

	void init() {
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			tam[i] = 0;
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
		if (u == v) return;

		int a = find(u);
		int b = find(v);

		if (tam[a] > tam[b]) swap(a, b);
		par[a] = b;
		tam[b] += tam[a];
	}

	int getAbove(int x) { //quem come X
		return n + x;
	}

	int getBelow(int x) { //quem eh comido por X
		return n + n + x;
	}

	bool sameKind(int u, int v) {
		if (u > n || v > n) return false;
		if (same(getAbove(u), v)) return false;
		if (same(getAbove(v), u)) return false;
		if (same(getBelow(u), v)) return false;
		if (same(getBelow(v), u)) return false;
		if (same(getBelow(u), getAbove(v))) return false;
		if (same(getBelow(v), getAbove(u))) return false;

		merge(u, v);
		merge(getAbove(u), getAbove(v));
		merge(getBelow(u), getBelow(v));

		return true;
	}

	bool canEat(int u, int v) {
		if (u > n || v > n) return false;
		if (u == v) return false;

		if (find(u) == find(v)) return false;
		if (same(u, getBelow(v))) return false;
		if (same(v, getAbove(u))) return false;
		if (same(getBelow(v), getBelow(u))) return false;
		if (same(getAbove(v), getAbove(u))) return false;

		merge(u, getAbove(v));
		merge(getBelow(u), v);
		merge(getBelow(v), getAbove(u));

		return true;
	}
};

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n, k; scanf("%d%d", &n, &k);
		int ans = 0;

		UF uf(n);
		while(k--) {
			int op, x, y; scanf("%d%d%d", &op, &x, &y);
			if (op == 1) {
				ans += !uf.sameKind(x, y);
			} else if (op == 2) {
				ans += !uf.canEat(x, y);
			}
		}
		printf("%d\n", ans);
	}
}