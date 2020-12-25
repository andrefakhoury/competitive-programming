#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

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

struct Segment {
	int i, j, x;

	Segment() {}
	Segment(int a, int b, int c) {
		i = a, j = b, x = c;
	}

	bool operator<(const Segment& p) const {
		return i < p.i;
	}
};

int main() {
	int n, q; scanf("%d%d", &n, &q);

	set<Segment> st;
	map<int, int> f;
	set<pair<int, int>> f_color;

	auto insert = [&](Segment x) {
		st.emplace(x);
		f[x.x] += x.j - x.i + 1;
		f_color.emplace(x.j - x.i + 1, x.x);
	};
	auto remove = [&](Segment x) {
		st.erase(x);
		f[x.x] -= x.j - x.i + 1;
		f_color.erase(make_pair(x.j - x.i + 1, x.x));
	};

	
	ST seg;

	insert(Segment(1, n, 1));
	insert(Segment(n+1, n+1, 0));

	while(q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			set<Segment>::iterator it;
			Segment sm;

			it = st.lower_bound(Segment(l, 0, 0));
			sm = *it;
			if (sm.i > l) {
				sm = *(--it);
				remove(*it);

				if (sm.i <= l-1) insert(Segment(sm.i, l-1, sm.x));
				if (l <= sm.j) insert(Segment(l, sm.j, sm.x));
			}

			it = st.upper_bound(Segment(r, 0, 0));
			sm = *(--it);
			if (sm.j > r) {
				remove(*it);

				if (sm.i <= r) insert(Segment(sm.i, r, sm.x));
				if (r+1 <= sm.j) insert(Segment(r+1, sm.j, sm.x));
			}

			set<Segment>::iterator itt, itt2;
			for (itt = itt2 = st.lower_bound(Segment(l, 0, 0)); itt != st.end() && (*itt).j <= r; itt = itt2) {
				sm = *itt;
				seg.update(sm.i, sm.j, abs(x - sm.x));
				itt2++;
				remove(*itt);
			}

			insert(Segment(l, r, x));
		} else if (op == 2) {
			int x; scanf("%d", &x);
			printf("%d\n", f[x]);
		} else {
			printf("%d\n", f_color.rbegin()->first);
		}
	}
}