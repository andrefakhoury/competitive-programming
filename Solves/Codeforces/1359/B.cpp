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

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

char mat[MAXN][MAXN];

inline void _solve_(int __ntest__) {
	int n, m, x, y; rd(n, m, x, y);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &mat[i][j]);
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] != '.') continue;
			if (j < m && mat[i][j+1] == '.') {
				if (x+x > y) {
					mat[i][j] = mat[i][j+1] = '*';
					ans += y;
				}
			}

			if (mat[i][j] == '.') {
				ans += x;
				mat[i][j] = '*';
			}
		}
	}

	printf("%lld\n", ans);

}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}