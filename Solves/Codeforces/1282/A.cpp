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
	int a, b, c, R;
	cin >> a >> b >> c >> R;

	if (a > b) swap(a, b);

	int l = c - R;
	int r = c + R;

	if (l > r) swap(l, r);

	int a1 = max(0, b - r);
	int a2 = max(0, l - a);
	int ans = min(b-a, a1+a2);

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();
	return 0;
}