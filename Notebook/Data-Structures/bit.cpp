#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct BIT {
	int bt[MAXN];

	BIT() {
		memset(bt, 0, sizeof bt);
	}

	inline void update(int i, int k) {
		for (i++; i < MAXN; i += i&-i)
			bt[i] += k;
	}

	inline int query(int i) {
		int ret = 0;
		for (i++; i; i -= i&-i)
			ret += bt[i];
		return ret;
	}

	inline int query(int l, int r) {
		return query(r) - query(l-1);
	}
};