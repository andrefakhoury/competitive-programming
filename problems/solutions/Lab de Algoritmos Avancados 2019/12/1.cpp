#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int memo[21][201][201];

int solve(int i, int cur, int S, vector<vector<int> > prices) {
	if (cur > S) return INT_MIN;
	if (i == (int)prices.size()) return 0;

	if (~memo[i][cur][S]) return memo[i][cur][S];

	int& ret = memo[i][cur][S];
	ret = INT_MIN;

	for (int k : prices[i]) {
		ret = max(ret, k + solve(i+1, cur+k, S, prices));
	}

	return ret;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(memo, -1, sizeof memo);

		int m, c; scanf("%d%d", &m, &c);
		vector<vector<int> > prices(c);
		for (int i = 0; i < c; i++) {
			int k; scanf("%d", &k);
			prices[i].resize(k);
			for (int& j : prices[i]) scanf("%d", &j);
		}

		int ans = solve(0, 0, m, prices);
		if (ans < 0) printf("no solution\n");
		else printf("%d\n", ans);
	}
}
