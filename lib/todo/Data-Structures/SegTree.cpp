#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	struct Node {
		// dont forget to set neutral elements (0 for add, INF for min, etc)
		int val = 0;
		int lazy = 0;
		bool lazy_is_set = false;


		inline void apply_lazy(int i, int j, int v) {
			lazy_is_set = true;
			lazy += v;
		}
		inline void apply_value(int i, int j, int v) {
			val += v;
		}
	};

	inline Node merge(Node const& L, Node const& R) {
		Node ret;
		ret.val = max(L.val, R.val);
		return ret;
	}

	int n;
	vector<Node> seg;

	void prop(int p, int i, int j) {
		if (seg[p].lazy_is_set) {
			seg[p].apply_value(i, j, seg[p].lazy);
			if (i != j) {
				int m = (i + j) / 2;
				seg[p + p].apply_lazy(i, m, seg[p].lazy)
				seg[p + p + 1].apply_lazy(m + 1, j, seg[p].lazy);
			}
			seg[p].lazy_is_set = false;
		}
	}
	
	SegTree(int n) : n(n), seg(4 * n) {}

	template<typename Tp>
	void build(int p, int i, int j, vector<Tp> const& v) {
		if (i == j) {
			seg[p].apply(v[i]);
		} else {
			int m = (i + j) / 2;
			build(p + p, i, m, v);
			build(p + p + 1, m + 1, j, v);
			seg[p] = merge(seg[p + p], seg[p + p + 1]);
		}
	}

	template<typename Tp>
	void build(vector<Tp> const& v) {
		build(1, 0, n-1, v);
	}

	template<typename Tp>
	void update(int p, int i, int j, int l, int r, Tp const&... x) {
		if (i > j) return;
		prop(p, i, j);
		if (i > r || j < l) return;

		if (i >= l && j <= r) {
			seg[p].lazy = x;
			prop(p, i, j);
		} else {
			int m = (i + j) / 2;
			update(p + p, i, m, l, r, x);
			update(p + p + 1, m + 1, j, l, r, x);
			seg[p] = merge(seg[p + p], seg[p + p + 1]);
		}
	}

	Node query(int p, int i, int j, int l, int r) {
		if (i > j) return {};
		prop(p, i, j);
		if (i > r || j < l) return {};
		if (i >= l && j <= r) return seg[p];
		int m = (i + j) / 2;
		Node L = query(p + p, i, m, l, r);
		Node R = query(p + p + 1, m + 1, j, l, r);
		return merge(L, R);
	}

	template<typename Tp> void update(int l, int r, Tp&& x) { update(1, 0, n-1, l, r, x); }
	Node query(int l, int r) { return query(1, 0, n-1, l, r); }
};

int main() {
	int n; scanf("%d", &n);
	SegTree seg(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	seg.build(a);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			printf("%d %d: %d\n", i, j, seg.query(i, j));
		}
	}
}