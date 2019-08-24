struct ST {
	vector<ll> seg, lazy;
 
	ST() {
		seg = vector<ll>(4 * MAXN);
		lazy = vector<ll>(4 * MAXN);
 
		fill(seg.begin(), seg.end(), 0ll);
		fill(lazy.begin(), lazy.end(), 0ll);
	}
 
	ll merge(ll i, ll j) {
		return i + j;
	}
 
	void prop(int p, int i, int j) {
		if (!lazy[p]) return;
 
		seg[p] += lazy[p] * (j - i + 1);
 
		if (i != j) {
			lazy[2 * p] += lazy[p];
			lazy[2 * p + 1] += lazy[p];
		}
 
		lazy[p] = 0;
	}
 
	ll query(int p, int i, int j, int l, int r) {
		if (i > j || j < l || i > r) return 0;
		prop(p, i, j);
 
 
		if (i >= l && j <= r) {
			return seg[p];
		}
 
		int m = (i + j) / 2;
 
		ll L = query(2 * p, i, m, l, r);
		ll R = query(2 * p + 1, m+1, j, l, r);
 
		return merge(L, R);
	}
 
	ll query(int l, int r) {
		return query(1, 1, MAXN - 1, l, r);
	}
 
	void update(int p, int i, int j, int l, int r, ll x) {
 
		prop(p, i, j);
 
		if (i > j || j < l || i > r) return;
 
		if (i >= l && j <= r) {
			lazy[p] += x;
			prop(p, i, j);
			return;
		}
 
		int m = (i + j) / 2;
 
		update(2 * p, i, m, l, r, x);
		update(2 * p + 1, m+1, j, l, r, x);
 
		seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
	}
 
	void update(int l, int r, ll x) {
		update(1, 1, MAXN-1, l, r, x);
	}
};