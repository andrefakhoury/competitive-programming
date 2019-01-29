#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int light[101];
int memo[101][(1 << 16) + 5];

int solve(int i, const int n, int m, int qtd, int situation) {
	if (memo[i][situation]) return memo[i][situation];

	if (situation == 0) return memo[i][situation] = 0;
	if (i >= m) return memo[i][situation] = MAXN;

	int op1 = solve(i+1, n, m, qtd, situation);

	return memo[i][situation] = min(op1, 1 + solve(i+1, n, m, qtd+1, situation ^ light[i]));
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	int t; scanf("%d", &t);
	int caso = 1;
	while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int x; scanf("%d", &x);
				light[i] ^= x << j;
			}
		}

		int ans = solve(0, n, m, 0, (1 << (n)) - 1);

		printf("Case %d: ", caso++);
		if (ans <= m) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");

		memset(light, 0, sizeof light);
		memset(memo, 0, sizeof memo);
	}

	return 0;
}