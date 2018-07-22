#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int v[MAXN];
int st[MAXN];

int build(int p, int l, int r) {
	if (l == r) return 0;
	st[p] = build(2*p, l, (l+r)/2) + build(2*p+1, (l+r)/2+1, r);
}

int query(int p)