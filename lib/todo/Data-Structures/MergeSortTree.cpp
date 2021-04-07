#include <bits/stdc++.h>
using namespace std;

int v[100000];
vector<int> tree[262145];

struct MergeSortTree {
	int n;
	void build(int p, int i, int j) {
		tree[p].resize(j - i + 1);
		if (i == j) tree[p][0] = v[i];
		else {
			int m = (i + j) / 2;
			build(p + p, i, m);
			build(p + p + 1, m + 1, j);
			merge(tree[p+p].begin(), tree[p+p].end(), tree[p+p+1].begin(), tree[p+p+1].end(), tree[p].begin());
		}
	}

	int query(int p, int i, int j, int l, int r, int k) {
		if (i > r || j < l) return 0;
		if (i >= l && j <= r) return lower_bound(tree[p].begin(), tree[p].end(), k) - tree[p].begin();
		int m = (i + j) / 2;
		return query(p + p, i, m, l, r, k) + query(p + p + 1, m + 1, j, l, r, k);
	}
	inline int query(int l, int r, int k) { return query(1, 0, n-1, l, r, k); }

	inline int kth(int l, int r, int k) {
		int lo = -1e9, hi = 1e9, mi;
		while(lo < hi) {
			mi = lo + (hi - lo) / 2;
			if (query(l, r, mi+1) > k) hi = mi;
			else lo = mi + 1;
		}
		return lo;
	}

	MergeSortTree(int n) : n(n) { build(1, 0, n-1); }
};

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	MergeSortTree ms(n);
	while(q--) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", ms.kth(l-1, r-1, k-1));
	}
}