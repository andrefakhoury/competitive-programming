#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct SegTree {
	struct Node {
		int m1, m2;
	};

	vector<Node> seg;
	int n;

	SegTree() {}
	SegTree(int n) : n(n) {
		seg.resize(4 * n);
	}

	Node merge(Node const& a, Node const& b) {
		Node ret;
		if (a.m1 >= b.m1) {
			ret.m1 = a.m1;
			ret.m2 = max(a.m2, b.m1);
		} else {
			ret.m1 = b.m1;
			ret.m2 = max(a.m1, b.m2);
		}
		return ret;
	}

	void update(int p, int i, int j, int id, int val) {
		if (i == j) seg[p] = {val, -1};
		else {
			int m = (i + j) / 2;
			if (id <= m) update(p + p, i, m, id, val);
			else update(p + p + 1, m + 1, j, id, val);
			seg[p] = merge(seg[p+p], seg[p+p+1]);
		}
	}

	void update(int id, int val) {
		update(1, 0, n-1, id, val);
	}

	Node query(int p, int i, int j, int l, int r) {
		if (l > r or i > r or j < l) return {-1, -1};
		if (i >= l && j <= r) return seg[p];
		int m = (i + j) / 2;
		Node L = query(p + p, i, m, l, r);
		Node R = query(p + p + 1, m + 1, j, l, r);
		return merge(L, R);
	}

	Node query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	SegTree st(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.update(i, x);
	}

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		char c; cin >> c;
		int l, r; cin >> l >> r;
		if (c == 'U') st.update(l-1, r);
		else {
			SegTree::Node ans = st.query(l-1, r-1);
			cout << ans.m1 + ans.m2 << "\n";
		}
	}
}