// eh pra isso estar errado

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int st[4 * MAXN];
int h[MAXN];

void build(int p, int lo, int hi) {
	if (lo == hi) st[p] = h[lo];
	else {
		int mi = (lo + hi) / 2;
		build(2 * p, lo, mi);
		build(2 * p + 1, mi + 1, hi);
		st[p] = min(st[2*p], st[2*p+1]);
	}
}

int query(int p, int lo, int hi, int a, int b) {
	int mi = (lo + hi) / 2;

	if (lo > b || hi < a) return INT_MAX;
	if (lo >= a && hi <= b) return st[p];

	return min(query(2*p, lo, mi, a, b), query(2*p+1, mi+1, hi, a, b));
}

int query(int l, int r) {
	return query(1, 1, MAXN-1, l, r);
}

bool check(int l, int r, int w, int k) {
	if (r - l + 1 < w) return false;
	if (query(l, r) >= k) return true;
	if (r - l + 1 == w) return false;
	int m = (l + r) / 2;
	return check(l, m, w, k) || check(m+1, r, w, k);
}

int solve(int l, int r, int k) {
	int lo = 1, hi = 1e9, mi;

	while(lo < hi) {
		mi = (lo + hi + 1) / 2;
		if (check(l, r, k, mi)) lo = mi;
		else hi = mi - 1;
	}

	return lo;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", h+i);
	build(1, 1, MAXN - 1);

	int q; scanf("%d", &q);
	while(q--) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", solve(l, r, k));
	}

	return 0;
}