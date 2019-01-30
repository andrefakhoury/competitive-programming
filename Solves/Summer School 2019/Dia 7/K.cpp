#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct UF {
	int par[MAXN], tam[MAXN], tim[MAXN], n, m, curTime;

	UF() {}
	UF(int n, int m) {
		this->n = n;
		this->m = m;

		init();
		addRoads();
	}

	void init() {
		curTime = 0;
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			tam[i] = 1;
			tim[i] = 0;
		}
	}

	int find(int x, int t) {
		if (par[x] == x) return x;
		if (tim[x] > t)  return x;
		return find(par[x], t);
	}

	void merge(int u, int v, int t) {
		int a = find(u, t);
		int b = find(v, t);

		if (a == b) return;
		if (tam[a] > tam[b]) swap(a, b);

		par[a] = b;
		tim[a] = t;
		tam[b] += tam[a];
	}

	void addRoads() {
		for (int k = m; k >= 1; k--) {
			curTime++;
			for (int i = 2 * k; i <= n; i += k) {
				merge(k, i, curTime);
			}
		}
	}

	int getTime(int u, int v) {
		int lo = 0, hi = 100001, mi, ans = -1;
		while (lo < hi) {
			mi = (lo + hi)/2;

			if (find(u, mi) == find(v, mi)) {
				hi = mi;
				ans = mi;
			} else {
				lo = mi + 1;
			}
		}
		return ans;
	}
};

int main() {
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	UF uf(n, m);

	while(q--) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%d\n", uf.getTime(u, v));
	}
}