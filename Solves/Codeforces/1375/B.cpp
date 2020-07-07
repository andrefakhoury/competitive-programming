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
inline void _solve_(int __ntest__) {
	int n, m; rd(n, m);
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rd(b[i][j]);
		}
	}

	auto valid = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < n && j < m;
	};

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if (valid(i+dx[k], j+dy[k]))
					a[i][j]++;
			}
			ok &= b[i][j] <= a[i][j];
		}
	}

	if (ok) {
		puts("YES");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	} else puts("NO");


}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}