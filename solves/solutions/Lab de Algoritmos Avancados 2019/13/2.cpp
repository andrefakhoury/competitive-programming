#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int memo[1000][300];

int solve(int i, int cur, int n, int S, vector<int>& p, vector<int>& w) {
	if (cur > S) return -INF;
	if (i >= n) return 0;

	int& ret = memo[i][cur];
	if (~ret) return ret;

	int tk = p[i] + solve(i+1, cur+w[i], n, S, p, w);
	int nt = solve(i+1, cur, n, S, p, w);

	return ret = max(tk, nt);
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		vector<int> p(n), w(n);
		for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &w[i]);
		int g; scanf("%d", &g);
		vector<int> m(g);
		for (int& i : m) scanf("%d", &i);

		ll ans = 0;
		for (int c : m) {
			memset(memo, -1, sizeof memo);
			ans += solve(0, 0, n, c, p, w);
		}

		printf("%lld\n", ans);
	}
}