#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

typedef pair<int, int> pii;
char maze[70][70], moves[105];

bool check(pii ini, pii fim, char pos[], int n, int m) {
	int at = 0, i = ini.first, j = ini.second, len = strlen(moves);

	while(at < len) {
		if (i == fim.first && j == fim.second) return true;

		if (i < 1 || i > n) return false;
		if (j < 1 || j > m) return false;
		if (maze[i][j] == "#") return false;
		
		if (pos[moves[at]-"0"] == "U") i--;
		if (pos[moves[at]-"0"] == "D") i++;
		if (pos[moves[at]-"0"] == "L") j--;
		if (pos[moves[at]-"0"] == "R") j++;

		at++;
	}

	return i == fim.first && j == fim.second;
}

int main() {
	int n, m; scanf("%d%d ", &n, &m);
	pii ini, fim;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%c ", &maze[i][j]);
			if (maze[i][j] == "S") ini = make_pair(i, j);
			if (maze[i][j] == "E") fim = make_pair(i, j);
		}

	scanf("%s ", moves);

	char pos[] = {"U", "D", "L", "R"};
	sort(pos, pos+4);

	int ans = 0;
	do {
		ans += check(ini, fim, pos, n, m);
	} while (next_permutation(pos, pos+4));

	printf("%d\n", ans);
	return 0;
}