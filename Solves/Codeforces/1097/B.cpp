#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 30;
const int INF = 0x3f3f3f3f;

int n, a[MAXN], memo[MAXN][400];

bool solve(int i, int d) {
	if (i > n) return d == 0;
	if (memo[i][d] != -1) return memo[i][d];

	return memo[i][d] = solve(i+1, (d+a[i])%360) or solve(i+1, (d-a[i]+360)%360);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	memset(memo, -1, sizeof memo);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	if (solve(1, 0)) printf("YES\n");
	else printf("NO\n");

	return 0;
}