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
	string s; cin >> s;

	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'A') continue;

		int j;
		for (j = i-1; j >= 0; j--) {
			if (s[j] == 'A') {
				ans = max(ans, i - j);
				break;
			}
		}
		i = j + 1;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}