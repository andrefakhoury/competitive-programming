#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[60][60], b[60][60];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> a[i][j];

	vector<pii> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
				ans.eb(i, j);
				b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (a[i][j] != b[i][j]) return cout << -1 << '\n', 0;
	}

	cout << ans.size() << "\n";
	for (auto pp : ans) {
		cout << pp.fi << " " << pp.se << "\n";
	}


	return 0;
}