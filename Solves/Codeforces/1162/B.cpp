#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

pii mat[60][60];
int m1[60][60], m2[60][60];

void impossible() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mat[i][j].first;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mat[i][j].second;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mat[i][j].first > mat[i][j].second)
				swap(mat[i][j].first, mat[i][j].second);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j].first > m1[i-1][j] && mat[i][j].first > m1[i][j-1]) {
				m1[i][j] = mat[i][j].first;
				if (mat[i][j].second > m2[i-1][j] && mat[i][j].second > m2[i][j-1]) {
					m2[i][j] = mat[i][j].second;
				} else {
					impossible();
				}
			} else {
				impossible();
			}
		}
	}

	cout << "Possible\n";
	return 0;
}