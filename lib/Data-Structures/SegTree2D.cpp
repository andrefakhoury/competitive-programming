struct Seg2D {
	struct Node {
		int val = 0;

		inline void apply(ll x) {
			val = x;
		}

		inline void merge(Node const& l, Node const& r) {
			val = max(l.val, r.val);
		}
	};

	int n, m;
	vector<vector<Node>> seg;

	Seg2D(int n, int m) : n(n), m(m) { // size of each dimension must be 2^(1 + ceil(log2 n)). Be careful with MLE
		seg = vector<vector<Node>>(1 << (32 - __builtin_clz(n - 1) + 1), vector<Node>(2 * m + 1));
	}

	inline void updateY(int px, int p, int val) {
		for(p += m, seg[px][p].apply(val); p > 1; p >>= 1) {
			seg[px][p >> 1].merge(seg[px][p], seg[px][p^1]);
		}
	}

	void updateX(int p, int i, int j, int x, int y, int val) {
		if (i != j) {
			int m = (i + j) / 2;
			if (x <= m) updateX(2 * p + 1, i, m, x, y, val);
			else updateX(2 * p + 2, m + 1, j, x, y, val);
		}
		updateY(p, y, val);
	}

	void update(int x, int y, int val) {
		updateX(0, 0, n - 1, x, y, val);
	}

	Node queryY(int p, int l, int r) {
		Node ans;
		for (l += m, r += m + 1; l < r; l >>= 1, r >>= 1) {
			if(l&1) ans.merge(ans, seg[p][l++]);
			if(r&1) ans.merge(ans, seg[p][--r]);
		}
		return ans;
	}

	Node queryX(int p, int i, int j, int lx, int ly, int rx, int ry) {
		if (i < lx || j > rx) {
			int mi = (i + j) / 2;
			if (mi >= rx) return queryX(2 * p + 1, i, mi, lx, ly, rx, ry);
			else if (mi < lx) return queryX(2 * p + 2, mi + 1, j, lx, ly, rx, ry);
			Node ans;
			Node L = queryX(2 * p + 1, i, mi, lx, ly, rx, ry);
			Node R = queryX(2 * p + 2, mi + 1, j, lx, ly, rx, ry);
			ans.merge(L, R);
			return ans;
		}
		return queryY(p, ly, ry);
	}

	Node query(int lx, int ly, int rx, int ry) {
		return queryX(0, 0, n - 1, lx, ly, rx, ry);
	}
};