#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	int tcase = 0;
	while(cin >> n, n) {
		int T; cin >> T;

		vector<int> t(n - 1);
		for (int i = 0; i < n - 1; i++) cin >> t[i];

		int m1; cin >> m1;
		vector<int> go(m1);
		for (int i = 0; i < m1; i++) cin >> go[i];

		int m2; cin >> m2;
		vector<int> og(m2);
		for (int i = 0; i < m2; i++) cin >> og[i];

		vector<vector<tiii>> travel(n);

		// 0 >>>
		for (int i = 0; i < m1; i++)
			travel[0].eb(go[i], 1, go[i] + t[0]);
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < m1; j++) {
				int last = get<2>(travel[i-1][j]);
				travel[i].eb(last, i + 1, last + t[i]);
			}
		}
		// n-1 <<<<<
		travel[n-1].resize(m1, {-1, -1, T + 1});
		for (int i = 0; i < m2; i++)
			travel[n-1].eb(og[i], n-2, og[i] + t[n-2]);
		for (int i = n-2; i > 0; i--) {
			for (int j = 0; j < m2; j++) {
				int last = get<2>(travel[i+1][m1 + j]);
				travel[i].eb(last, i - 1, last + t[i - 1]);
			}
		}

		vector<vector<int>> memo(n, vector<int>(T + 2, T + 1));
		for (int i = 0; i <= T; i++) memo[n-1][i] = T - i;
		for (int tm = T - 1; tm >= 0; tm--) {
			for (int i = 0; i < n; i++) {
				for (auto const& [ts, u, tt] : travel[i]) if (ts >= tm && tt <= T) {
					memo[i][tm] = min(memo[i][tm], ts - tm + memo[u][tt]);
				}
			}
		}

		int ans = memo[0][0];
		cout << "Case Number " << ++tcase << ": ";
		if (ans <= T) cout << ans << "\n";
		else cout << "impossible\n";
	}
}