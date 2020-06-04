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

int mat[100][100];

map<ll, int> st;
void solve(int x1, int y1, int x2, int y2, ll sum) {
	if (x1 > x2) return;
	if (y1 > y2) return;

	sum += mat[x1][y1];

	if (x1 == x2 && y1 == y2) {
		st[sum]++;
	} else {
		solve(x1+1, y1, x2, y2, sum);
		solve(x1, y1+1, x2, y2, sum);
	}
}

int main() {
	int n = 50;

	mat[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		mat[i][1] = mat[i-1][1] + i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			mat[i][j] = mat[i][j-1] + j + i - 2;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		printf("%3d ", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	solve(1, 1, 25, 6, 0);
	printf("%ld\n", st.size());
	for (auto p : st) {
		printf("%lld: %d\n", p.fi, p.se);
	}

}