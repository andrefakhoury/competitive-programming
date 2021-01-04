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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k; cin >> n >> m >> k;

	vector<string> a(n);
	for (string& s : a) cin >> s;

	auto paint_row = [&](vector<string>& a, int r) {
		for (int i = 0; i < m; i++) a[r][i] = 'R';
	};
	auto paint_col = [&](vector<string>& a, int c) {
		for (int i = 0; i < n; i++) a[i][c] = 'R';
	};
	auto count = [&](vector<string>& a) {
		int ret = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			ret += a[i][j] == '#';
		return ret;
	};

	int row = 1 << n;
	int col = 1 << m;

	int ans = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			vector<string> b = a;
			for (int k = 0; k < n; k++) if (i & (1 << k)) paint_row(b, k);
			for (int k = 0; k < m; k++) if (j & (1 << k)) paint_col(b, k);
			ans += count(b) == k;
		}
	}

	cout << ans << "\n";
}