// amortizadamente O(n)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<pair<int, int>, int> ppi;
typedef long long ll;

char mat[55][55];

void solve(int i, int j) {
	if (!mat[i][j]) return;
	mat[i][j] = 0;

	solve(i+1, j);
	solve(i-1, j);
	solve(i, j+1);
	solve(i, j-1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	int I, J;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'O') I = i, J = j;
		}
	}

	solve(I, J);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '*') {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;
}