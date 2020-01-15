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
const int MOD = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll memo[12][1003][1003];

int n, m;
ll solve(int k, int a, int b) {
	if (k == m) return 1;
	if (memo[k][a][b]) return memo[k][a][b];

	ll ans = solve(k+1, a, b);
	if (a+1 <= b) ans = (ans + solve(k, a+1, b)) % MOD;
	if (a <= b-1) ans = (ans + solve(k, a, b-1)) % MOD;
	if (a+2 <= b) ans = (ans - solve(k, a+1, b-1));
	while(ans < 0) ans = (ans + MOD) % MOD;

	return memo[k][a][b] = ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	cout << solve(0, 1, n) << '\n';
	return 0;
}