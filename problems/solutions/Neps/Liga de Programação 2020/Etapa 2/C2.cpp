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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

struct cosa {
	int noka, val;
} mat[MAXN][MAXN];

int memo[353][353][6][1<<4][3];
map<char, int> posmask;
int delta[3][2] = { {1, 0}, {0, 1}, {0, -1} };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	posmask['N'] = 0;
	posmask['O'] = 1;
	posmask['K'] = 2;
	posmask['A'] = 3;

	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			string s;
			cin >> s;
			if (posmask.count(s[0])) mat[i][j] = {true, 1 << posmask[s[0]]};
			else mat[i][j] = {false, stoi(s)};
		}
	}
	
	cout << solve(1, 1, 0, 0, 0) << '\n';
}