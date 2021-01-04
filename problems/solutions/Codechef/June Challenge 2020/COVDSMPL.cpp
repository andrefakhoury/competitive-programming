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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Query {
	pii x, y;

	Query(int a, int b, int c, int d) : x(a, b), y(c, d) { }

	Query(pii x, pii y) : x(x), y(y) { }

	bool operator<(Query const& q) const {
		return mk(x, y) < mk(q.x, q.y);
	}
};

inline void _solve() {
	int n, p; cin >> n >> p;
	map<Query, int> mp;

	auto ask = [&](Query const q) {
		if (mp.count(q)) return mp[q];
		int X = 0;
		if (q.x.fi <= q.y.fi && q.x.se <= q.y.se) {
			cout << 1 << " " << q.x.fi << " " << q.x.se << " " << q.y.fi << " " << q.y.se << "\n";
			cout.flush();
			cin >> X;
		}

		if (X == -1) exit(0);
		return mp[q] = X;
	};

	vector<vector<int>> ans(n+1, vector<int>(n+1));

	auto guess = [&]() {
		cout << "2\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
		cout.flush();

		int X; cin >> X;
		if (X == -1) exit(0);
	};


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = ask({1, 1, i, j}) - ask({1, 1, i-1, j}) - ask({1, 1, i, j-1}) + ask({1, 1, i-1, j-1});
		}
	}

	guess();
}

int main() {
	int T; cin >> T;
	while(T--) _solve();
}