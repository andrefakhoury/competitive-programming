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

const int MAXN = 351, INF = 0x3f3f3f3f;

struct cosa {
	int noka, val;
} mat[MAXN][MAXN];

int memo[353][353][6][1<<4][3];
map<char, int> posmask;

int n, m, k;
int delta[3][2] = { {1, 0}, {0, 1}, {0, -1} };

int solve(int i, int j, int p, int mask, int last) {
	if ((i > n && j == m) or (i == n && j > m)) return 0;
	else if (i > n or j > m) return -INF;
	if (i <= 0 or j <= 0) return -INF;

	int& ret = memo[i][j][p][mask][last];
	if (vis[i][j][p][mask][last]) return ret;
	vis[i][j][p][mask][last] = 1;
	ret = -INF;

	// ja to usando
	if (p > 0) {
		for (int kk = 0; kk < 3; kk++) {
			if ((last == 2 && kk == 1) or (last == 1 && kk == 2)) continue;
			ret = max(ret, solve(i+delta[kk][0], j+delta[kk][1], p-1, 0, kk));
		}
		return ret;
	}

	int curr = 0;
	if (mat[i][j].noka) mask |= mat[i][j].val;
	else curr = mat[i][j].val;

	// uso
	if ((mask+1) == (1<<4)) {
		for (int kk = 0; kk < 3; kk++) {
			if ((last == 2 && kk == 1) or (last == 1 && kk == 2)) continue;
			ret = max(ret, curr + solve(i+delta[kk][0], j+delta[kk][1], k, 0, kk));
		}
	}

	for (int kk = 0; kk < 3; kk++) {
			if ((last == 2 && kk == 1) or (last == 1 && kk == 2)) continue;
		ret = max(ret, curr + solve(i+delta[kk][0], j+delta[kk][1], 0, mask, kk));
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	posmask['N'] = 0;
	posmask['O'] = 1;
	posmask['K'] = 2;
	posmask['A'] = 3;

	cin >> n >> m >> k;
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