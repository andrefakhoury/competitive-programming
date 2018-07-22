#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int v[MAXN], st[4*MAXN];
void build(int node, int l, int r) {
	if (l == r) st[node] = v[l];
	else {
		build(2*node, l, (l+r)/2);
		build(2*node+1, (l+r)/2+1, r);
		st[node] = st[2*node] + st[2*node+1];
	}
}

void update(int node, int l, int r, int id, int x) {
	if (l == r) {
		v[l] = x;
		st[node] = x;
	} else {
		int mid = (l+r)/2;
		if (l <= id && id <= mid) update(2*node, l, mid, id, x);
		else update(2*node+1, mid+1, r, id, x);
		st[node] = st[2*node] + st[2*node+1];
	}
}

int query(int node, int l, int r, int a, int b) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) return st[node];
	int mid = (l+r)/2;
	return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}


int main() {
	int n, q, op, k, x;
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= n; i++) scanf("%d", v+i);
	build(1, 1, n);

	while(q--) {
		scanf("%d%d", &op, &k);
		if (op) printf("%d\n", query(1, 1, n, 1, k));
		else {
			scanf("%d", &x);
			update(1, 1, n, k, x);
		}
	}

	return 0;
}