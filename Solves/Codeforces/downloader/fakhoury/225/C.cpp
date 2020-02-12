#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 2e6;
 int memo[MAXN][MAXN][2];
char s[MAXN][MAXN];
int qt[2][MAXN];
int n, m, x, y;
 int solve(int j, int sum, int cur) {
 if (sum > y) return INF;
 if (j > m) return sum >= x ? 0 : INF;
  int& ret = memo[j][sum][cur];
 if (~ret) return ret;
  ret = qt[!cur][j] + solve(j+1, sum+1, cur);
 if (sum >= x) ret = min(ret, qt[cur][j] + solve(j+1, 1, !cur));
  return ret;
}
 int main() {
 memset(memo, -1, sizeof memo);
  scanf("%d%d%d%d", &n, &m, &x, &y);
 for (int i = 1; i <= n; i++) scanf(" %s", s[i]+1);
  for (int j = 1; j <= m; j++) {
  for (int i = 1; i <= n; i++) {
   qt[0][j] += s[i][j] == '#';
   qt[1][j] += s[i][j] == '.';
  }
 }
  printf("%d\n", min(solve(1, 0, 0), solve(1, 0, 1)));
 return 0;
}