#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mset(x, y) memset((x), (y), sizeof(x))
typedef long long ll;
const int MAXN = 30;

int mat[MAXN][MAXN], n, m;
ll k;

ll solve(int i, int j, ll p) {
	if (i >= n || j >= m) return 0;
	p ^= ll(mat[i][j]);

	return (p == k) + solve(i, j+1, p) + solve(i+1, j, p);

}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	cout << solve(0, 0, 0) << endl;
	return 0;
}
