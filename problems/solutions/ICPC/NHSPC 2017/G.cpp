#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e6 + 5, MAXX = 1 << 21;
const int INF = MAXN;

int a[MAXN];

struct SegT {
	struct Node {
		vector<int> has;

		inline Node() {
			has.resize(21, int());
		}

		inline void merge(Node& a, Node& b) {
			for (int i = 0; i < 21; i++) {
				if (a.has[i] && b.has[i])
					has[i] = min(a.has[i], b.has[i]);
				else if (a.has[i])
					has[i] = a.has[i];
				else
					has[i] = b.has[i];
			}
		}

		inline void reverse() {
			for (int i = 0; i < 10; i++) swap(has[i], has[20-i]);
		}

		inline void set(int x, int pos) {
			has[pos] = x;
		}

		~Node() {
			has.clear();
		}
	};

	vector<Node> seg;
	vector<int> lazy;
	int n;

	inline SegT(int n) : n(n) {
		seg.resize(4 * n + 1, Node());
		lazy.resize(4 * n + 1, int());
	}

	void build(int p, int l, int r) {
		if (l == r) seg[p].set(l, __builtin_popcount(a[l]));
		else {
			int m = (l + r) / 2;
			build(p+p, l, m);
			build(p+p+1, m+1, r);
			seg[p].merge(seg[p+p], seg[p+p+1]);
		}
	}

	inline void prop(int p, int l, int r) {
		if (lazy[p]) {
			seg[p].reverse();
			if (l != r) {
				lazy[p+p] = !lazy[p+p];
				lazy[p+p+1] = !lazy[p+p+1];
			}
			lazy[p] = 0;
		}
	}

	// <diff, ind>
	pii query(int p, int i, int j, int l, int r, int v) {
		prop(p, i, j);
		if (i > j || j < l || i > r) return {INF, INF};

		if (i >= l && j <= r) {
			pii ans = {INF, INF};
			for (int k = v; k < 21; k++) if (seg[p].has[k])
				ans = min(ans, {abs(v-k), seg[p].has[k]});
			for (int k = v; k >= 0; k--) if (seg[p].has[k])
				ans = min(ans, {abs(v-k), seg[p].has[k]});
			return ans;
		}

		int m = (i + j) / 2;
		pii L = query(p+p, i, m, l, r, v);
		pii R = query(p+p+1, m+1, j, l, r, v);
		return min(L, R);
	}

	inline int query(int l, int r, int v) {
		return query(1, 1, n, l, r, __builtin_popcount(v)).second;
	}

	void update(int p, int i, int j, int l, int r) {
		prop(p, i, j);
		if (i > j || j < l || i > r) return;

		if (i >= l && j <= r) {
			lazy[p] = !lazy[p];
			prop(p, i, j);
		} else {
			int m = (i + j) / 2;
			update(p+p, i, m, l, r);
			update(p+p+1, m+1, j, l, r);
			seg[p].merge(seg[p+p], seg[p+p+1]);
		}
	}

	inline void update(int l, int r) {
		update(1, 1, n, l, r);
	}

	~SegT() {
		lazy.clear();
		seg.clear();
	}
};

inline void _solve() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	SegT seg(n);
	seg.build(1, 1, n);

	while(q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r, v; scanf("%d%d%d", &l, &r, &v);
			printf("%d\n", seg.query(l, r, v));
		} else {
			int l, r; scanf("%d%d", &l, &r);
			seg.update(l, r);
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		printf("Case %d:\n", cs);
		_solve();
	}
}