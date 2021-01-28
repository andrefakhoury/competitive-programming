template <typename T>
struct SegTree {
	struct Node {
		T val, lazy;
		Node() : val(1e16) {}
		Node(T val) : val(val), lazy(0) {}
	};

	T merge(T l, T r) {
		return min(l, r);
	}

	Node merge(Node l, Node r) {
		Node ans;
		ans.val = merge(l.val, r.val);
		ans.lazy = 0;
		return ans;
	}

	int n;
	vector<Node> seg;

	SegTree() : n(), seg() {}
	SegTree(int n) : n(n), seg(4 * n) { }

	void prop(int p, int i, int j) {
		if (seg[p].lazy) {
			seg[p].val += seg[p].lazy;
			if (i != j) {
				seg[p+p].lazy += seg[p].lazy;
				seg[p+p+1].lazy += seg[p].lazy;
			}
		}
		seg[p].lazy = 0;
	}

	void init(int n) {
		this->n = n;
		seg.resize(4 * n);
	}

	void build(int p, int i, int j, vector<T>& v) {
		if (i == j) seg[p] = v[i];
		else {
			int m = (i + j) / 2;
			build(p + p, i, m, v);
			build(p + p + 1, m + 1, j, v);
			seg[p] = merge(seg[p+p], seg[p+p+1]);
		}
	}

	void build(vector<T>& v) {
		if (n == 0) init(v.size());
		build(1, 0, n - 1, v);
	}

	void update(int p, int i, int j, int l, int r, T val) {
		prop(p, i, j);
		if (i > j || i > r || j < l) return;
		if (i >= l && j <= r) {
			seg[p].lazy = val;
			prop(p, i, j);
		} else {
			int m = (i + j) / 2;
			update(p+p, i, m, l, r, val);
			update(p+p+1, m+1, j, l, r, val);
			seg[p] = merge(seg[p+p], seg[p+p+1]);
		}
	}

	void update(int l, int r, T val) {
		update(1, 0, n-1, l, r, val);
	}

	T query(int p, int i, int j, int l, int r) {
		prop(p, i, j);
		if (i > j || i > r || j < l) return Node().val;
		if (i >= l && j <= r) return seg[p].val;
		else {
			int m = (i + j) / 2;
			T L = query(p+p, i, m, l, r);
			T R = query(p+p+1, m+1, j, l, r);
			return merge(L, R);
		}
	}

	T query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};