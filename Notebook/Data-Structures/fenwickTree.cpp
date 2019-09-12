#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

class BIT {
	ll bt[MAXN+10];

	public:
	BIT() {
		memset(bt, 0, sizeof bt);
	}

	void update(int i, int val) {
		while (i <= MAXN) {
			bt[i] += val;
			i += i&-i;
		}
	}

	ll query(int i) {
		ll ret = 0;
		while (i > 0) {
			ret += bt[i];
			i -= i&-i;
		}
		return ret;
	}

	ll query(int i, int j) {
		if (i > j) return 0;
		if (i == j) return query(i);
		
		return query(j) - query(i-1);
	}
};