#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
 typedef pair<int, int> pii;
 const int MAXN = 505;
 int ord[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 char mat[MAXN][MAXN];
vector<pii> edges[MAXN][MAXN];
 void dfs(int i, int j, int& cnt, int s, int k) {
 if (mat[i][j] != '.') return;
 if (cnt == s - k) return;
  mat[i][j] = '!';
 cnt++;
  for (auto p : edges[i][j]) dfs(p.fi, p.se, cnt, s, k);
}
 int main() {
 int n, m, k; scanf("%d%d%d", &n, &m, &k);
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   scanf(" %c", &mat[i][j]);
  }
 }
  int s = 0, x, y;
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   if (mat[i][j] != '.') continue;
   s++;
   x = i, y = j;
    for (int l = 0; l < 4; l++) {
    int I = i + ord[l][0];
    int J = j + ord[l][1];
     if (mat[I][J] != '.') continue;
    edges[i][j].eb(I, J);
   }
  }
 }
  int cnt = 0;
 dfs(x, y, cnt, s, k);
  for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   printf("%c", mat[i][j] == '!' ? '.' : mat[i][j] == '.' ? 'X' : mat[i][j]);
  }
  printf("\n");
 }
}