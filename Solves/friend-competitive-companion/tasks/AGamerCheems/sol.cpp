#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e5 + 5;
const ll INF = 1e16;

ll memo[100][100]; // todo

struct Qry {
	int op, l, r;
	void read() {
		rd(op, l, r);
	}
};

vector<ll> seg[2];

int main() {
	int n, m, x; rd(n, m, x);
	vector<Qry> q(m);
	for (int i = 0; i < m; i++) q[i].read();

	seg[0].resize(4 * n);
	seg[1].resize(4 * n);

	int act = 0;
	for (int i = m-1; i >= 0; i--) {
		int left = get_left(i);
		int right = get_right(i);
		for (int y = 1; y <= n; y++) {
			if (covers(i, y)) {
				memo[i][y] = min(abs(left - y) + memo[i+1][left], abs(right - y) + memo[i+1][right]);
			} else memo[i][y] = memo[i+1][y];
		}
	}

	printf("%d\n", memo[0][x]);

}
