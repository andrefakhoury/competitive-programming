#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
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
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

int vis[MAXN][MAXN];
char a[MAXN][MAXN];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pii> all[MAXN*MAXN];

inline bool can(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(int i, int j, int c) {
	if (!can(i, j)) return 1;
	if (a[i][j] == '.') return 1;
	if (vis[i][j] != -1) return 0;

	vis[i][j] = c;

	bool is = 0;
	for (int k = 0; k < 4; k++) {
		is |= dfs(i+dx[k], j+dy[k], c);
	}
	if (is) all[c].eb(i, j);

	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X') x = i, y = j;
		}
	}


	mset(vis, -1);

	dfs(x, y, 0);
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#' && vis[i][j] == -1) {
				dfs(i, j, ++c);
			}
		}
	}

	if (c == 0) {
		cout << -1 << "\n";
		return 0;
	}

	auto dist = [](pii a, pii b) {
		return abs(a.fi - b.fi) + abs(a.se - b.se) - 1;
	};

	int ans = INT_MAX;
	for (int i = 1; i <= c; i++) {
		for (pii X : all[0]) {
			for (pii Y : all[i]) {
				ans = min(ans, dist(X, Y));
			}
		}
	}
	
	cout << ans << "\n";
}