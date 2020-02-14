#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e6 + 5;
int a[MAXN];

// update_min: set a[i] = min(a[i], x) for each i in [l, r]
// update_sum: set a[i] = a[i] + x for each i in [l, r]
// query_sum: sum of all elements in [l, r]
// query_max: max of all elements in [l, r]
struct SegT {
	struct Node {
		int max1, max2, cntMax;
		long long sum;
		inline Node() : max1(), max2(), cntMax(), sum() {}
		inline Node(int max1, int max2, int cntMax, ll sum) : max1(max1), max2(max2), cntMax(cntMax), sum(sum) {}
		inline void merge(Node const& l, Node const& r) {
			this->sum = l.sum + r.sum;

			if (l.max1 == r.max1) {
				this->max1 = l.max1;
				this->cntMax = l.cntMax + r.cntMax;
				this->max2 = max(l.max2, r.max2);
			} else if (l.max1 > r.max1) {
				this->max1 = l.max1;
				this->cntMax = l.cntMax;
				this->max2 = max(l.max2, r.max1);
			} else {
				this->max1 = r.max1;
				this->cntMax = r.cntMax;
				this->max2 = max(r.max2, l.max1);
			}
		}
	} seg[4 * MAXN];
	int lazy_min[4 * MAXN];
	long long lazy_sum[4 * MAXN];

	void build(int p, int i, int j) {
		lazy_min[p] = 0;
		if (i == j) {
			seg[p] = Node(a[i], -1, 1, a[i]);
		} else {
			int m = (i + j) / 2;
			build(p+p, i, m);
			build(p+p+1, m+1, j);
			seg[p].merge(seg[p+p], seg[p+p+1]);
		}
	}

	inline void prop_min(int p, int i, int j) {
		if (lazy_min[p]) {
			int x = lazy_min[p];
			lazy_min[p] = 0;
			if (seg[p].max1 <= x) return;

			if (i != j) {
				lazy_min[p+p] = lazy_min[p+p] ? min(lazy_min[p+p], x) : x;
				lazy_min[p+p+1] = lazy_min[p+p+1] ? min(lazy_min[p+p+1], x) : x;
			}

			if (seg[p].max2 < x) {
				seg[p].sum -= ll(seg[p].max1 - x) * seg[p].cntMax;
				seg[p].max1 = x;
			}
		}
	}

	inline void prop_sum(int p, int i, int j) {
		if (lazy_sum[p]) {
			seg[p].sum += lazy_sum[p] * (j - i + 1);
			seg[p].max1 += lazy_sum[p];
			seg[p].max2 += seg[p].max2 > 0 ? lazy_sum[p] : 0;

			if (i != j) {
				lazy_sum[p+p] += lazy_sum[p];
				lazy_sum[p+p+1] += lazy_sum[p];
			}

			lazy_sum[p] = 0;
		}
	}

	void update_min(int p, int i, int j, int l, int r, int x) {
		prop_min(p, i, j);
		prop_sum(p, i, j);
		if (i > j || i > r || j < l) return;

		if (i >= l && j <= r) {
			lazy_min[p] = x;
			prop_min(p, i, j);
			if (seg[p].max2 < x) return;
		}

		int m = (i + j) / 2;
		update_min(p+p, i, m, l, r, x);
		update_min(p+p+1, m+1, j, l, r, x);
		seg[p].merge(seg[p+p], seg[p+p+1]);
	}

	void update_sum(int p, int i, int j, int l, int r, ll x) {
		prop_min(p, i, j);
		prop_sum(p, i, j);
		if (i > j || i > r || j < l) return;

		if (i >= l && j <= r) {
			lazy_sum[p] += x;
			prop_sum(p, i, j);
		} else {
			int m = (i + j) / 2;
			update_sum(p+p, i, m, l, r, x);
			update_sum(p+p+1, m+1, j, l, r, x);
			seg[p].merge(seg[p+p], seg[p+p+1]);
		}
	}

	ll query_sum(int p, int i, int j, int l, int r) {
		prop_min(p, i, j);
		prop_sum(p, i, j);
		if (i > j || i > r || j < l) return 0;
		if (i >= l && j <= r) return seg[p].sum;
		int m = (i + j) / 2;
		return query_sum(p+p, i, m, l, r) + query_sum(p+p+1, m+1, j, l, r);
	}

	int query_max(int p, int i, int j, int l, int r) {
		prop_min(p, i, j);
		prop_sum(p, i, j);
		if (i > j || i > r || j < l) return -1;
		if (i >= l && j <= r) return seg[p].max1;
		int m = (i + j) / 2;
		return max(query_max(p+p, i, m, l, r), query_max(p+p+1, m+1, j, l, r));
	}
} seg;

int main() {
	int T, n, q, op, l, r, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++) scanf("%d", a+i);
		seg.build(1, 1, n);

		while(q--) {
			scanf("%d%d%d", &op, &l, &r);
			if (op == 0) {
				scanf("%d", &x);
				seg.update_min(1, 1, n, l, r, x);
			} else if (op == 1) {
				scanf("%d", &x);
				seg.update_sum(1, 1, n, l, r, x);
			} else if (op == 2) {
				printf("%d\n", seg.query_max(1, 1, n, l, r));
			} else {
				printf("%lld\n", seg.query_sum(1, 1, n, l, r));				
			}
		}
	}

	return 0;
}