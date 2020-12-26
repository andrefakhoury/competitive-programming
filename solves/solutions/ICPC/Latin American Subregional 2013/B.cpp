#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 5, MAXX = 1e6 + 5;
 
struct Point {
	int x, y;
 
	Point() {}
	Point(int a, int b) {
		x = a, y = b;
	}
 
	void print() {
		printf("%d ", x);
		if (~y) printf("%d", y);
		printf("\n");
	}
};
 
struct Line {
	Point a, b;
 
	Line() {}
 
	void read() {
		int x, y;
 
		scanf("%d%d", &x, &y);
		a = Point(x, y);
 
		scanf("%d%d", &x, &y);
		b = Point(x, y);
 
		if (a.x > b.x) swap(a, b);
	}
 
	bool operator<(const Line& l) const {
		return min(a.y, b.y) > min(l.a.y, l.b.y);
	}
};
 
struct ST {
	vector<int> seg, lazy;
 
	ST() {
		seg = vector<int>(4 * MAXX);
		lazy = vector<int>(4 * MAXX);
 
		fill(seg.begin(), seg.end(), 0);
		fill(lazy.begin(), lazy.end(), 0);
	}
 
	int merge(int i, int j) {
		return max(i, j);
	}
 
	void prop(int p, int i, int j) {
		if (!lazy[p]) return;
 
		seg[p] = max(seg[p], lazy[p]);
 
		if (i != j) {
			lazy[2 * p] = lazy[p];
			lazy[2 * p + 1] = lazy[p];
		}
 
		lazy[p] = 0;
	}
 
	int query(int p, int i, int j, int l, int r) {
		if (i > j || j < l || i > r) return 0;
 
		prop(p, i, j);
 
		if (i >= l && j <= r) {
			return seg[p];
		}
 
		int m = (i + j) / 2;
 
		int L = query(2 * p, i, m, l, r);
		int R = query(2 * p + 1, m+1, j, l, r);
 
		return merge(L, R);
	}
 
	int find(int l, int r) {
		return query(1, 0, MAXX - 1, l, r);
	}
 
	void update(int p, int i, int j, int l, int r, int x) {
 
		prop(p, i, j);
 
		if (i > j || j < l || i > r) return;
 
		if (i >= l && j <= r) {
			lazy[p] = merge(seg[p], x);
			prop(p, i, j);
			return;
		}
 
		int m = (i + j) / 2;
 
		update(2 * p, i, m, l, r, x);
		update(2 * p + 1, m+1, j, l, r, x);
 
		seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
	}
 
	void update(int l, int r, int x) {
		update(1, 0, MAXX-1, l, r, x);
	}
};
 
vector<Line> A;
vector<int> edges[MAXN];
Point final[MAXN];
bool vis[MAXN];
 
Point solve(int x, ST& seg) {
	int id = seg.find(x, x);
 
	if (id) {
		Point ret = final[id-1];
		if (ret.x == -1) ret.x = x;
		return ret;
	} else {
		return Point(x, -1);
	}
}
 
Point dfs(int u) {
	if (vis[u]) return final[u];
	vis[u] = true;
 
	Point& a = A[u].a;
	Point& b = A[u].b;
 
	if (a.y == b.y) {
		final[u] = Point(-1, a.y);
	} else if (edges[u].size()) {
		final[u] = dfs(edges[u][0]);
		if (final[u].x == -1) final[u].x = a.y > b.y ? a.x : b.x;
	} else {
		final[u].x = a.y > b.y ? a.x : b.x;
		final[u].y = -1;
	}
 
	return final[u];
}
 
int main() {
	int n, q; scanf("%d%d", &n, &q);
 
	A.resize(n);
	for (Line& l : A) l.read();
 
	sort(A.begin(), A.end());
 
	ST seg;
 
	for (int i = 0; i < n; i++) {
		Line l = A[i];
 
		if (l.a.y < l.b.y) {
			int id = seg.find(l.b.x, l.b.x);
			if (id) edges[i].push_back(id - 1);
		} else if (l.a.y > l.b.y) {
			int id = seg.find(l.a.x, l.a.x);
			if (id) edges[i].push_back(id - 1);
		}
 
		seg.update(l.a.x, l.b.x, i + 1);
	}
 
	for (int i = 0; i < n; i++) dfs(i);
 
	while(q--) {
		int x; scanf("%d", &x);
		solve(x, seg).print();
	}
 
	return 0;
}