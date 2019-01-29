#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

/** Union find: naive implementation */
struct UF_naive {
	int n, par[MAXN];

	void init() {
		for (int i = 0; i < MAXN; i++) par[i] = i;
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
		par[u] = v;
	}
};

/** Union Find with Path Compression */
struct UF_path {
	int par[MAXN];

	void init() {
		for (int i = 0; i < MAXN; i++) par[i] = i;
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void merge(int u, int v) {
		int a = find(u);
		int b = find(v);
		par[u] = v;
	}
};

/** Union Find with Union by Size */
struct UF_union {
	int par[MAXN], siz[MAXN];

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
		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		siz[b] += siz[a];
	}
};

/** Union Find with Union by Size and rollback */
struct UF_union_rb {
	int par[MAXN], siz[MAXN];
	stack<pair<int, int> > old_par;
	stack<pair<int, int> > old_siz;

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
		if (siz[a] > siz[b]) swap(a, b);
		old_par.push(make_pair(a, par[a]));
		old_siz.push(make_pair(b, siz[b]));

		par[a] = b;
		siz[b] += siz[a];
	}

	void rollback() {
		if (old_par.size() == 0) return;
		if (old_siz.size() == 0) return;

		par[old_par.top().first] = old_par.top().second;
		siz[old_par.top().first] = old_par.top().second;
		old_par.pop();
		old_siz.pop();
	}
};

/** "Partially Persistent" Union Find with Union by Size */
struct UF_union_pp {
	int time;
	int par[MAXN], siz[MAXN], tim[MAXN];

	void init() {
		time = 0;
		for (int i = 0; i < MAXN; i++) {
			par[i] = i;
			siz[i] = 1;
			tim[i] = 0;
		} 
	}

	int find(int x, int t) {
		if (par[x] == x) return x;
		if (tim[x] >  t) return x;
		return find(par[x], t);
	}

	void merge(int u, int v) {
		time++;

		int a = find(u, time);
		int b = find(v, time);
		if (siz[a] > siz[b]) swap(a, b);
		par[a] = b;
		tim[a] = time;
		siz[b] += siz[a];
	}
};

int main() {
	return 0;
}