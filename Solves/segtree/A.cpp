#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int st[4*MAXN], v[MAXN];

void build(int node, int l, int r) {
	if (l == r)
		st[node] = (v[l] > 0) ? 1 : (v[l] < 0) ? -1 : 0;
	else {
		int mid = (l+r)/2;
		build(2*node, l, mid); 
		build(2*node+1, mid+1, r);
		st[node] = st[2*node] * st[2*node+1];
	}
}

void update(int node, int l, int r, int id, int x) {
	if (l == r) {
		v[l] = x;
		st[node] = v[l];
	} else {
		int mid = (l+r)/2;
		if (l <= id && id <= mid)
			update(2*node, l, mid, id, x);
		else update(2*node+1, mid+1, r, id, x);
		st[node] = st[2*node] * st[2*node+1];
	}
}

int query(int node, int l, int r, int a, int b) {
	if (l > b || r < a) return 1;
	if (l >= a && r <= b) return st[node];
	int mid = (l+r)/2;
	return query(2*node, l, mid, a, b) * query(2*node+1, mid+1, r, a, b);
}

int main() {
	char op;
	int n, q, k, x;
	while(scanf("%d%d", &n, &q) != EOF) {
		memset(v, 0, sizeof v);
		memset(st, 0, sizeof st);

		for (int i = 1; i <= n; i++) scanf("%d", v+i);
		build(1, 1, n);

		while(q--) {
			scanf(" %c %d%d", &op, &k, &x);
			if (op == 'P') {
				int r = query(1, 1, n, k, x);
				printf("%c", (r > 0) ? '+' : (r < 0) ? '-' : '0');
			} else if (op == 'C') {
				update(1, 1, n, k, (x > 0) ? 1 : (x < 0) ? -1 : 0);
			}
		}
		printf("\n");
	}
}