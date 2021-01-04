#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

char grid[20][20];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	for (int cases = 1; cases <= t; cases++) {
		int ans = 0;
		int r, c; cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = )

		cout << "Case #" << cases << ": " << ans << '\n';
	}

	return 0;
}