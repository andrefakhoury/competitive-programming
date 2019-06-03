#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

#define fi first
#define se second

int a[MAXN][MAXN];
int n, m, k;

pair<int, int> maximum(int col) {
	pair<int, int> ans = {0, 1};
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = i; j <= min(n, i+k-1); j++) {
			if (a[j][col] == 1) cur++;
		}

		if (cur > ans.fi) {
			ans = {cur, i};
		}
	}

	return ans;
}

int qtt(int row, int col) {
	int ret = 0;
	for (int i = 1; i < row; i++) {
		if (a[i][col] == 1) ret++;
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	pair<int, int> ans = {0, 0};
	for (int i = 1; i <= m; i++) {
		pair<int, int> cur = maximum(i);
		ans.fi += cur.fi;
		ans.se += qtt(cur.se, i);
	}

	printf("%d %d\n", ans.fi, ans.se);
}