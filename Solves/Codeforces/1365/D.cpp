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

const int MAXN = 55 + 5, INF = 0x3f3f3f3f;

int dist[MAXN][MAXN];
char mat[MAXN][MAXN];
bool ans;
int n, m;
bool vis[MAXN][MAXN];

inline bool valid(int i, int j) {
	return i >= 1 && j >= 1 && i <= n && j <= m;
}

int dt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void flood_block(int i, int j) {
	if (!valid(i, j)) return;
	if (vis[i][j]) return;
	if (mat[i][j] == '#') return;
	if (mat[i][j] == '.') {
		mat[i][j] = '#';
		return;
	}
	if (mat[i][j] == 'G') {
		ans = false;
		return;
	}

	vis[i][j] = true;
	for (int k = 0; ans && k < 4; k++)
		flood_block(i+dt[k][0], j+dt[k][1]);
}

inline void _solve_(int __ntest__) {
	rd(n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &mat[i][j]);

	ans = true;
	mset(vis, 0);
	for (int i = 1; ans && i <= n; i++) {
		for (int j = 1; ans && j <= m; j++) {
			if (mat[i][j] == 'B') {
				flood_block(i, j);
			}
		}
	}

	if (ans) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			dist[i][j] = -1;
		if (mat[n][m] == '.') {
			queue<pii> q;
			q.emplace(n, m);
			dist[n][m] = 0;

			while(q.size()) {
				auto [ui, uj] = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int I = ui+dt[k][0];
					int J = uj+dt[k][1];
					if (valid(I, J) && mat[I][J] != '#' && dist[I][J] == -1) {
						q.emplace(I, J);
						dist[I][J] = dist[ui][uj] + 1;
					}
				}
			}
		}
	}

	for (int i = 1; ans && i <= n; i++) {
		for (int j = 1; ans && j <= m; j++) {
			if (mat[i][j] == 'G')
				ans &= dist[i][j] != -1;
			if (mat[i][j] == 'B')
				ans &= dist[i][j] == -1;
		}
	}

	printf("%s\n", ans ? "Yes" : "No");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}