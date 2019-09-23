#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 3e6, MAXX = 1e6 + 1;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Point {
	int x, y;
	
	Point() {}
};

struct Line {
	Point a, b;

	Line() {}

	void read() {
		cin >> a.x >> a.y >> b.x >> b.y;

		a.x += MAXX;
		a.y += MAXX;
		b.x += MAXX;
		b.y += MAXX;

		if (a.y > b.y) swap(a, b);
	}

	bool operator<(Line const& l) const {
		return a.y == l.a.y ? a.x < l.a.x : a.y < l.a.y;
	}
};

struct ST {
	vector<ll> seg, lazy;

	ST() {
		seg = vector<ll>(4 * MAXN);
		lazy = vector<ll>(4 * MAXN);

		fill(seg.begin(), seg.end(), 0ll);
		fill(lazy.begin(), lazy.end(), 0ll);
	}

	ll merge(ll i, ll j) {
		return max(i, j);
	}

	void prop(int p, int i, int j) {
		if (!lazy[p]) return;

		seg[p] = merge(seg[p], lazy[p]);

		if (i != j) {
			lazy[2*p] = lazy[p];
			lazy[2*p+1] = lazy[p];
		}

		lazy[p] = 0;
	}

	ll query(int p, int i, int j, int l, int r) {
		if (i > j || j < l || i > r) return 0;
		prop(p, i, j);

		if (i >= l && j <= r) return seg[p];

		int m = (i + j) / 2;

		ll L = query(2 * p, i, m, l, r);
		ll R = query(2 * p + 1, m+1, j, l, r);

		return merge(L, R);
	}

	ll query(int l) {
		return query(1, 1, MAXN - 1, l, l);
	}

	void update(int p, int i, int j, int l, int r, ll x) {
		prop(p, i, j);

		if (i > j || j < l || i > r) return;

		if (i >= l && j <= r) {
			lazy[p] = x;
			prop(p, i, j);
			return;
		}

		int m = (i + j) / 2;

		update(2 * p, i, m, l, r, x);
		update(2 * p + 1, m+1, j, l, r, x);

		seg[p] = merge(seg[2*p], seg[2*p+1]);
	}

	void update(int l, int r, ll x) {
		update(1, 1, MAXN - 1, l, r, x);
	}
};

int nxt[MAXN];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	vector<Line> lines(n);

	for (Line& l : lines) l.read();

	sort(lines.begin(), lines.end());

	ST seg;

	int cur = 1;
	for (Line& l : lines) {
		nxt[cur] = seg.query(l.a.x);
		seg.update(min(l.a.x, l.b.x), max(l.a.x, l.b.x), cur);

		cur++;
	}

	int x; cin >> x;
	x += MAXX;

	int ind = seg.query(x);
	int ans = x;

	while(ind) {
		ans = lines[ind-1].a.x;
		ind = nxt[ind];
	}

	cout << ans - MAXX << endl;
}