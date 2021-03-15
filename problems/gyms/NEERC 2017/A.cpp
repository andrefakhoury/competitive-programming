#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 4e5 + 5, INF = 0x3f3f3f3f;
const int BKSZ = 630;

struct Op {
	int x, y; 
	int tp;
	int idx;

	inline void read(int idx) {
		this->idx = idx;
		rd(tp, x, y);
	}

} pts[MAXN];

bitset<MAXN> bks[BKSZ+10];

inline int get_block(int i) {
	return (i-1) / BKSZ + 1;
}

inline void add(int k, int l, int r) {
	int bl = get_block(l);
	int br = get_block(r);

	for (int i = bl; i <= br; i++)
		bks[i][k] = 1;
}

inline void rem(int k, int l, int r) {
	int bl = get_block(l);
	int br = get_block(r);

	for (int i = bl; i <= br; i++)
		bks[i][k] = 0;
}

inline ll dist(ll x1, ll y1, ll x2, ll y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

inline bool valid(Op const& a, Op const& b) {
	ll d1 = dist(a.x, a.y, b.x, b.y);
	return d1 < ll(a.y) * a.y;
}

int main() {
	int n; rd(n);

	vector<int> allX;
	for (int i = 1; i <= n; i++) {
		pts[i].read(i);
		allX.eb(pts[i].x-pts[i].y);
		allX.eb(pts[i].x+pts[i].y);
	}

	sort(allX.begin(), allX.end());
	allX.erase(unique(allX.begin(), allX.end()), allX.end());

	auto getX = [&](int x) {
		return lower_bound(allX.begin(), allX.end(), x) - allX.begin() + 1;
	};

	for (int i = 1; i <= n; i++) {
		if (pts[i].tp == 1) {
			int x1 = getX(pts[i].x - pts[i].y);
			int x2 = getX(pts[i].x + pts[i].y);
			add(i, x1, x2);
		} else {
			int x = getX(pts[i].x);
			int bk = get_block(x);

			int ans = -1;

			for (int xn = bks[bk]._Find_first(); xn <= n; xn = bks[bk]._Find_next(xn)) {
				if (valid(pts[xn], pts[i])) {
					ans = xn;
					break;
				}
			}

			if (ans != -1) {
				int x1 = getX(pts[ans].x - pts[ans].y);
				int x2 = getX(pts[ans].x + pts[ans].y);
				rem(ans, x1, x2);
			}

			printf("%d\n", ans);
		}
	}
}