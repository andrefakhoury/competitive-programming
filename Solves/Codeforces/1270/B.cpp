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
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	pii ans = {-1, -1};
	for (int i = 0; i < n-1; i++) {
		if (abs(a[i] - a[i+1]) >= 2) {
			ans = {i+1, i+2};
		}
	}

	if (ans.fi != -1) {
		cout << "YES\n";
		cout << ans.fi << " " << ans.se << '\n';
	} else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}