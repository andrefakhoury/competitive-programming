#include <string>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 1005;

int n, x, y;
bool used[MAXN][MAXN];
bool ROW[MAXN];

vector<string> ans;
vector<int> cur;

bool checkDiagonal(int r, int c) {
	for (int i = r+1, j = c+1; i <= n and j <= n; i++, j++)
		if (used[i][j]) return false;
	
	for (int i = r+1, j = c-1; i <= n and j >= 1; i++, j--)
		if (used[i][j]) return false;
	
	for (int i = r-1, j = c+1; i >= 1 and j <= n; i--, j++)
		if (used[i][j]) return false;
	
	for (int i = r-1, j = c-1; i >= 1 and j >= 1; i--, j--)
		if (used[i][j]) return false;

	return true;
}

void solve(int col) {
	if (col > n) {
		string s;
		for (int i : cur) s += to_string(i) + ' ';
		ans.push_back(s);
		return;
	}

	if (col == y) {
		cur.push_back(x);
		solve(col + 1);
		cur.pop_back();
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (ROW[i]) continue;
		if (!checkDiagonal(i, col)) continue;

		used[i][col] = true;
		ROW[i] = true;
		cur.push_back(i);

		solve(col+1);

		used[i][col] = false;
		ROW[i] = false;
		cur.pop_back();
	}
}

int main() {
	while(cin >> n >> x >> y) {
		cout << "Solution\n";

		memset(used, 0, sizeof used);
		memset(ROW, 0, sizeof ROW);

		used[x][y] = true;
		ROW[x] = true;
		ans.clear();
		cur.clear();

		solve(1);

		for (string s : ans) cout << s << "\n";
	}
}