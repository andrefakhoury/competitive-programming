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

const int INF = 0x3f3f3f3f;

inline void isolve() {
	int n; cin >> n;
	string I, O; cin >> I >> O;

	vector<vector<int>> ans(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j : {i-1, i+1}) {
			if (j < 0 or j == n) continue;
			if (O[i] == 'Y' && I[j] == 'Y')
				ans[i][j] = 1;
		}
		ans[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (ans[i][j] < INF ? 'Y' : 'N');
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":\n";
		isolve();
	}
}