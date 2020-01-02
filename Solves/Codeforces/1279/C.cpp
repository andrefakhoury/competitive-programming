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

inline void _solve() {
	int n, m; cin >> n >> m;

	vector<int> a(n+1), b(m+1), vis(n+1);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];

	ll ans = 0;
	int last = 0, lixo = 0;
	for (int i = 1; i <= m; i++) {
		ans++;
		if (vis[b[i]]) lixo--;

		if (!vis[b[i]]) {
			
			ans += 2 * lixo;
			for (int j = last+1; j <= n && a[j] != b[i]; j++) {
				ans += 2;
				vis[a[j]] = true;
				last = j;
				lixo++;
			}

			last++;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}