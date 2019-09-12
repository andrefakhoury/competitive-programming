#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN];

struct SegTree {
	int st[4 * MAXN];

	SegTree() {
		build();
	}

	int merge(int a, int b) {
		return a + b;
	}

	void build(int p = 1, int lo = 0, int hi = MAXN-1) {
		if (lo == hi) st[p] = a[lo];
		else {
			int mi = (lo + hi) / 2;
			build(2 * p, lo, mi);
			build(2 * p + 1, mi + 1, hi);
			st[p] = merge(st[2*p], st[2*p+1]);
		}
	}

	int query(int p, int lo, int hi, int a, int b) {
		if (lo > b || hi < a) return 0; //out of bounds
		if (lo >= a && hi <= b) return st[p];

		int mi = (lo + hi)/2;
		int l = query(2*p, lo, mi, a, b);
		int r = query(2*p+1, mi+1, hi, a, b);

		return merge(l, r);
	}

	int query(int lo, int hi) {
		return query(1, 0, MAXN-1, lo, hi);
	}
};