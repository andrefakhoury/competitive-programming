#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int a[MAXN];

struct SegTree {
	int n;
	int seg[4 * MAXN];

	void build(int p, int i, int j) {
		if (i == j) seg[p] = a[i];
		else {
			int m = (i + j) / 2;
			build(p+p, i, m);
			build(p+p+1, m+1, j);
			seg[p] = gcd(seg[p+p], seg[p+p+1]);
		}
	}

	void init(int n) {
		this->n = n;
		build(1, 0, n-1);
	}

	int query(int p, int i, int j, int l, int r) {
		if (i >= l && j <= r) return seg[p];
		else if (i > r or j < l) return 0;
		else {
			int m = (i + j) / 2;
			int L = query(p+p, i, m, l, r);
			int R = query(p+p+1, m+1, j, l, r);
			return gcd(L, R);
		}
	}

	inline int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
} st;

struct Query {
	int l, r, d;
};

vector<int> divs[1000005];

inline void _solve_(int __ntest__) {
	int n, q; rd(n, q);
	for (int i = 0; i < n; i++) {
		rd(a[i]);
		if (divs[a[i]].empty()) {
			for (int j = 1; j * j <= a[i]; j++) {
				if (a[i]%j == 0) {
					divs[a[i]].eb(j);
					if (j * j != a[i]) divs[a[i]].eb(a[i]/j);
				}
			}
		}
	}
	st.init(n);
	
	vector<int> allQ;

	vector<Query> qry(q);
	for (Query& i : qry) {
		rd(i.l, i.r, i.d);
		i.l--, i.r--;
		allQ.eb(i.d);
	}

	sort(allQ.begin(), allQ.end());
	allQ.erase(unique(allQ.begin(), allQ.end()), allQ.end());

	map<int, vector<pair<int, pii>>> mp;

	auto getfi = [&](int i, int d) {
		int lo = i, hi = n-1, mi, ans = i;
		while(lo <= hi) {
			mi = (lo + hi) / 2;

			int cur = st.query(i, mi);
			if (cur == d) ans = mi, hi = mi-1;
			else if (gcd(cur, d) == d) lo = mi+1;
			else hi = mi-1;
		}

		for (int j = max(i, ans-2); j <= min(n-1, ans+2); j++) {
			if (st.query(i, j) == d) return j;
		}
		return -1;
	};

	auto getse = [&](int i, int d) {
		int lo = i, hi = n-1, mi, ans = i;
		while(lo < hi) {
			mi = (lo + hi + 1) / 2;
			int cur = st.query(i, mi);
			if (cur == d) ans = mi, lo = mi;
			else if (gcd(cur, d) == d) lo = mi;
			else hi = mi-1;
		}

		for (int j = min(n-1, ans+2); j >= max(i, ans-2); j--) {
			if (st.query(i, j) == d) return j;
		}

		return -1;
	};

	for (int i = 0; i < n; i++) for (int d : divs[a[i]]) {
		if (binary_search(allQ.begin(), allQ.end(), d) == 0) continue;
		pii cur = {getfi(i, d), getse(i, d)};
		if (cur.fi == -1 or cur.se == -1) continue;
		mp[d].eb(i, cur);
	}

	for (Query& qr : qry) {
		ll ans = 0;
		for (auto v : mp[qr.d]) {
			int L = v.fi;
			pii R = v.se;

			if (L >= qr.l && L <= qr.r) {
				ans += min(R.se, qr.r) - max(R.fi, qr.l) + 1;
			}
		}

		printf("%lld\n", ans);
	}
}

int main() {
	#ifndef LOCAL_PC
	freopen("gcdrng.in", "r", stdin);
	#endif

	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}