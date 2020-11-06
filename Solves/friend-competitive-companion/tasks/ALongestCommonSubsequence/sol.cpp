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

int n, m;
string s, t;
vector<vector<int>> memo;
int solve(int i, int j) {
	if (i >= n || j >= m) return 0;
	int& ret = memo[i][j];
	if (~ret) return ret;
	ret = max(solve(i + 1, j), solve(i, j + 1));
	if (s[i] == t[j]) ret = max(ret, solve(i + 1, j + 1) + 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while(getline(cin, s) && getline(cin, t)) {
		n = s.size();
		m = t.size();
		memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
		cout << solve(0, 0) << "\n";
	}
}