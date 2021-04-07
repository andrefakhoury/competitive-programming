


struct Seg2D {
	struct Node {
		ll val = LLONG_MIN;

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
		int qn = 1 << (32 - __builtin_clz(n - 1));
		int qm = 2 * m;
		seg = vector<vector<Node>>(qn, vector<Node>(qm));
	}

	inline void updateY(int px, int p, int val) {
		for(p += m, seg[px][p].apply(val); p > 0; p >>= 1) {
			seg[px][p >> 1].merge(seg[px][p], seg[px][p^1])
		}
	}

	void updateX(int p, int i, int j, int x, int y, int val) {
		if (i != j) {
			int mi = (i + j) / 2;
			if (x <= mi) updateX(p + p, i, mi, x, y, val);
			else updateX(p + p + 1, mi + 1, j, x, y, val);
		}
		updateY(p, y, val);
	}

	void update(int x, int y, int val) {
		updateX(1, 1, n, x, y, val);
	}

	Node queryY(int p, int l, int r) {
		Node ans;
		for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
			if(l&1) ans.merge(ans, seg[p][l++]);
			if(r&1) ans.merge(ans, seg[p][--r]);
		}
		return ans;
	}

	Node queryX(int p, int i, int j, int lx, int ly, int rx, int ry) {
		if (i < lx || j > rx) {
			int mi = (i + j) / 2;
			if (mi >= rx) return queryX(p+p, i, mi, lx, ly, rx, ry);
			else if (mi < lx) return queryX(p+p+1, mi+1, j, lx, ly, rx, ry);
			Node ans;
			Node L = queryX(p+p, i, mi, lx, ly, rx, ry);
			Node R = queryX(p+p+1, mi+1, j, lx, ly, rx, ry);
			ans.merge(L, R);
			return ans;
		}
		return queryY(p, ly, ry);
	}

	Node query(int lx, int ly, int rx, int ry) {
		return queryX(1, 1, n, lx, ly, rx, ry);
	}
};