#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int t[MAXN], X, Y, x, y;
int mat[505][505], freq[505][505];
string s;

void next(int& i, int& j, char c) {
	int I = i, J = j;
	if (c == 'U') I -= 1;
	if (c == 'R') J += 1;
	if (c == 'L') J -= 1;
	if (c == 'D') I += 1;

	if (J == 0 || J > Y || I == 0 || I > X) {
		return;
	} else {
		i = I, j = J;
	}
}

void dfs(int at, int i, int j, int T) {
	if (at == s.size()) {
		return;
	}

	mat[i][j] = min(mat[i][j], T);
	next(i, j, s[at]);
	dfs(at+1, i, j, T+1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	memset(mat, 0x3f, sizeof mat);

	cin >> X >> Y >> x >> y >> s;
	int n = s.size();

	for (int i = 1; i <= X; i++) {
		for (int j = 1; j <= Y; j++) {
			mat[i][j] =  n;
		}
	}

	dfs(0, x, y, 0);

	for (int i = 1; i <= X; i++) {
		for (int j = 1; j <= Y; j++) {
			t[mat[i][j]]++;
		}
	}

	for (int i = 0; i <= n; i++)
		cout << t[i] << ' ';
	cout << endl;
}