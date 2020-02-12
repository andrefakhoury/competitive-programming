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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	int ans = 0, ok = 0, cur = 1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == cur) {
			cur++;
			ok = 1;
		} else {
			ans++;
		}

	}

	if (!ok) cout << -1 << '\n';
	else cout << ans << '\n';
	

	return 0;
}