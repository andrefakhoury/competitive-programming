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

int a[MAXN];
int seg[4 * MAXN];
void build(int p, int i, int j) {
	if (i == j) {
		seg[p] = a[i];
	} else {
		int m = (i + j) / 2;
		build(p+p, i, m);
		build(p+p+1, m+1, j);
		seg[p] = min(seg[p+p], seg[p+p+1]);
	}
}

int query(int p, int i, int j, int l, int r) {
	if (i > r || j < l) return INF;
	if (i >= l && j <= r) return seg[p];
	int m = (i + j) / 2;
	int L = query(p+p, i, m, l, r);
	int R = query(p+p+1, m+1, j, l, r);
	return min(L, R);
}

void update(int p, int i, int j, int k, int x) {
	if (i == j) {
		seg[p] = a[k] = x;
	} else {
		int m = (i + j) / 2;
		if (k <= m) update(p+p, i, m, k, x);
		else update(p+p+1, m+1, j, k, x);
		seg[p] = min(seg[p+p], seg[p+p+1]);
	}
}

struct BIT {
	int sg[4 * MAXN];
	BIT() {
		memset(sg, 0, sizeof sg);
	}

	void update(int p, int i, int j, int k) {
		if (i == j){
			sg[p] = 1;
		} else {
			int m = (i + j) / 2;
			if (k <= m) this->update(p+p, i, m, k);
			else this->update(p+p+1, m+1, j, k);
			sg[p] = sg[p+p] + sg[p+p+1];
		}
	}

	int query(int p, int i, int j, int l, int r) {
		if (i > r || j < l) return 0;
		if (i >= l && j <= r) return sg[p];
		int m = (i + j ) /2;
		int L = this->query(p+p, i, m, l, r);
		int R = this->query(p+p+1, m+1, j, l, r);
		return L + R;
	}
} carry;

int n, k; 
vector<int> pos[MAXN];
int qtt[MAXN];

inline int find_range(int LO, int val) {
	int lo = LO, hi = n;
	while(lo < hi) {
		int mi = (lo + hi + 1) / 2;
		if (qtt[mi] - carry.query(1, 1, n, mi, n) >= val) lo = mi;
		else hi = mi-1;
	}

	return lo;
}

int main() {
	rd(n, k);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		pos[a[i]].eb(i);
	}

	build(1, 1, n);
	
	set<int> cur;
	int num = k+1;
	for (int i = n; i >= 1; i--) {
		cur.emplace(a[i]);
		qtt[i] = cur.size();
	}

	int last = 1;
	for (int i = 1, j = k; i <= k; i++, j--) {
		int r = find_range(last, j);

		int who = query(1, 1, n, last, r); // menor cara tal que 
		printf("%d ", who);

		last = *lower_bound(pos[who].begin(), pos[who].end(), last);
		last += 1;

		carry.update(1, 1, n, pos[who].back());
		for (int p : pos[who]) {
			update(1, 1, n, p, INF);
		}

	}
	printf("\n");
}