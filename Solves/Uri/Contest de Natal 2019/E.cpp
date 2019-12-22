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
const int MAXN = 1e4 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mat[MAXN][3];
ll memo[MAXN][3];

ll solve(int i, int c, const int n) {
	if (i == n) return 0;
	if (mat[i][c]) return INF;

	ll& ret = memo[i][c];
	if (~ret) return ret;

	ret = INF;
	for (int j = 0; j < 3; j++) {
		ret = min(ret, abs(c-j) + solve(i+1, j, n));
	}

	return ret;
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		ll ans = INF;
		for (int i = 0; i < 3; i++) 
			ans = min(ans, abs(1-i) + solve(0, i, n));

		printf("%lld\n", ans);
	}

	
	return 0;
}