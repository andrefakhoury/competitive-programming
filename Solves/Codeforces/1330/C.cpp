#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void answer(vector<int>& a) {
	for (int i : a) cout << i << " ";
	cout << "\n";
	exit(0);
}

inline void imp() {
	cout << -1 << "\n";
	exit(0);
}

int seg2[4 * MAXN];
int lzy2[4 * MAXN];

inline void prop2(int p, int i, int j) {
	if (lzy2[p]) {
		seg2[p] = lzy2[p];
		if (i != j) {
			lzy2[p+p] = lzy2[p];
			lzy2[p+p+1] = lzy2[p];
		}

		lzy2[p] = 0;
	}
}

void update2(int p, int i, int j, int l, int r, int x) {
	prop2(p, i, j);
	if (i > j || i > r || j < l) return;
	if (i >= l && j <= r) {
		lzy2[p] = x;
		prop2(p, i, j);
	} else {
		int m = (i + j) / 2;
		update2(p+p, i, m, l, r, x);
		update2(p+p+1, m+1, j, l, r, x);
	}
}

int query2(int p, int i, int j, int l, int r) {
	prop2(p, i, j);
	if (i > j || i > r || j < l) return -1;
	if (i >= l && j <= r) {
		return seg2[p];
	} else {
		int m = (i + j) / 2;
		int L = query2(p+p, i, m, l, r);
		int R = query2(p+p+1, m+1, j, l, r);
		if (L != -1) return L;
		return R;
	}
}

int main() {
	int n, k; rd(n, k);
	vector<pii> a(k);
	vector<int> b(k);
	for (int i = 0; i < k; i++) {
		rd(a[i].fi);
		a[i].se = i;
		b[i] = a[i].fi;
	}

	vector<int> ans(k);

	int ok = 0;
	for (int i = 0; i < k; i++) {
		ans[a[i].se] = i + 1;
		ok = max(ok, i + a[i].fi);
	}

	int last = n;
	for (int i = k-1; i > 0; i--) {
		if (a[i].fi + i >= last) break;
		int pos = max(ans[a[i-1].se]+1, last - a[i].fi + 1);
		ans[a[i].se] = pos;
		last = pos-1;
	}

	for (int i = 0; i < k; i++) {
		update2(1, 1, n, ans[i], ans[i] + b[i] - 1, i+1);
	}

	set<int> all;
	for (int i = 1; i <= n; i++) {
		int cur = query2(1, 1, n, i, i);
		if (cur <= 0) imp();
		else all.emplace(cur);
	}

	if ((int)all.size() != k) imp();
	for (int i = 0; i < k; i++)
		if (ans[i] + a[i].fi - 1 > n) imp();

	answer(ans);
}