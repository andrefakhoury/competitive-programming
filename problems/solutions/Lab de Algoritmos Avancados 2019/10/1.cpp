#include <iostream>
#include <vector>
#include <string>
using namespace std;

int go(int i, int j, vector<string>& grid, vector<vector<bool> >& vis) {
	if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[0].size()) return 0;
	if (vis[i][j]) return 0;

	vis[i][j] = true;

	if (grid[i][j] == 'L') return 0;

	int ret = 1;
	for (int kk = -1; kk <= 1; kk++) {
		for (int ii = -1; ii <= 1; ii++) {
			ret += go(i+kk, j+ii, grid, vis);
		}
	}

	return ret;
}

int solve(vector<string>& grid, int a, int b) {
	vector<vector<bool> > vis(grid.size());
	for (int i = 0; i < (int)grid.size(); i++) {
		vis[i].resize(grid[0].size());
		fill(vis[i].begin(), vis[i].end(), false);
	}

	return go(a, b, grid, vis);
}

int main() {
	int t, aaa, flag = 1; scanf("%d ", &t);
	char s[100];

	for (int tt = 1; tt <= t; tt++) {
		vector<string> grid;
		if (tt == 1) flag = 1;

		SCAN_STR:
		if (flag) scanf("%[^\n\r] ", s);
		if (s[0] == 'L' || s[0] == 'W') {
			grid.push_back(string(s));
			flag = 1;
			goto SCAN_STR;
		}

		int i, j;

		SCAN_INT:
		sscanf(s, "%d %d", &i, &j);
		printf("%d\n", solve(grid, i-1, j-1));
		aaa = scanf("%[^\n\r] ", s);
		if (aaa <= 0) break;
		if (s[0] >= '0' && s[0] <= '9') goto SCAN_INT;
		flag = 0;
		if (tt != t) printf("\n");
	}
}