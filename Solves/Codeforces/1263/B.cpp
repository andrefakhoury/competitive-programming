#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];

		int ans = 0;
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				ok &= v[i] != v[j];
			}

			if (ok) continue;
			ans++;

			string bkp = v[i];
			for (int pos = 0, could = 1; could && pos < 4; pos++) {
				for (int k = 0; k < 9; k++) {
					string s = v[i];
					s[pos] = k + '0';

					bool can = true;
					for (int j = 0; j < n; j++) {
						if (i == j) continue;
						can &= s != v[j];
					}

					if (can) {
						v[i][pos] = k + '0';
						could = 0;
						break;
					}
				}

			}
		}

		cout << ans << '\n';
		for (auto s : v) cout << s << '\n';
	}

	return 0;
}