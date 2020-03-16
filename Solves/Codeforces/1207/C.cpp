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
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll memo[MAXN][3];
ll n, a, b;
string s;

ll solve(int i, int h) {
	if (i == n-1) {
		if (h == 1) return 0;
		return a + b;
	}

	ll& ret = memo[i][h];
	if (~ret) return ret;

	if (s[i] == '0') {
		if (h == 1) return ret = solve(i+1, 1);
		else return ret = min(b + solve(i+1, 2), b + a + solve(i+1, 1));
	}

	if (h == 1) return ret = a + b + solve(i+1, 2);
	return ret = b + solve(i+1, 2);
}

inline void _solve() {
	cin >> n >> a >> b >> s;
	ll ans = (n + 1) * b + n * a;

	memset(memo, -1, sizeof memo);
	cout << ans + solve(0, 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}