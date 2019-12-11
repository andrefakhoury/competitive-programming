#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char t[MAXN];

struct ST {
	vector<ll> seg, lazy;
	int n;
 
	ST(int n) {
		this->n = n;

		n += 100;
		seg = vector<ll>(4 * n);
		lazy = vector<ll>(4 * n);
 
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
		if (l > r) return 0;
		return query(1, 1, n, l, r);
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
		update(1, 1, n, l, r, x);
	}

	int get() {
		int cur = 0, ret = 0;
		for (int i = 1; i <= n; i++) {
			if (query(i, i) >= query(i-1, i-1)) cur++;
			else cur = 0;
			ret = max(ret, cur);
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;

	ST st(n);

	for (int i = 0; i < MAXN; i++) t[i] = 'X';

	int cur = 1;

	set<int> inv;
	for (int i = 0; i < n; i++) {
		cur += s[i] == 'R';
		cur -= s[i] == 'L';

		if (s[i] == '(') {
			if (t[cur] == ')') {
				st.update(cur, n, 2);
				inv.erase(cur);				
			} else if (t[cur] != '(') {
				st.update(cur, n, 1);
			}

			vector<int> toErase;
			for (auto it = inv.lower_bound(cur); it != inv.end(); it++) {
				if (st.query(0, *it) == 0) toErase.eb(*it);
			}
			for (int xx : toErase) inv.erase(xx);
		} else if (s[i] == ')') {
			if (t[cur] == '(') {
				st.update(cur, n, -2);
			} else if (t[cur] != ')') {
				st.update(cur, n, -1);
			}

			if (st.query(0, cur) < 0) {
				inv.emplace(cur);
			}
		}

		cout << (inv.size() ? -1 : st.get()) << '\n';
	}
	
	return 0;
}