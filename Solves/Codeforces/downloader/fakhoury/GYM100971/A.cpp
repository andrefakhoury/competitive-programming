#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef pair<int, int> pii;
 const int MAXN = 55;
 bool vis[MAXN][MAXN];
char mat[MAXN][MAXN], grid[MAXN][MAXN];
int n, m; 
 void imp() {
 printf("Impossible\n");
 exit(0);
}
 void amb() {
 printf("Ambiguous\n");
 exit(0);
}
 void flood(int i, int j) {
 if (i == 0 || j == 0 || i > n || j > m) return;
 if (grid[i][j] == '#' || grid[i][j] == '!') return;
  grid[i][j] = '!';
 flood(i+1, j);
 flood(i-1, j);
 flood(i, j+1);
 flood(i, j-1);
}
 bool check() {
 for (int I = 1; I <= n; I++) {
  for (int J = 1; J <= m; J++) {
   if (grid[I][J] == '.') return false;
  }
 }
 return true;
}
 void reset() {
 for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
  grid[i][j] = mat[i][j];
 }
}
 bool mustBe(int i, int j) {
 if (i == 0 || j == 0 || i > n || j > m) return false;
 if (grid[i][j] == '.') return true;
 if (grid[i][j] == '#') return false;
 if (vis[i][j]) return false;
  vis[i][j] = true;
  if (mustBe(i+1, j)) return true;
 if (mustBe(i-1, j)) return true;
 if (mustBe(i, j+1)) return true;
 if (mustBe(i, j-1)) return true;
  return false;
}
 int main() {
 scanf("%d%d", &n, &m);
  vector<pii> pos;
 pii NONE;
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   scanf(" %c", &mat[i][j]);
   grid[i][j] = mat[i][j];
   if (grid[i][j] == '.') NONE = {i, j};
  }
 }
  bool ok = true;
 for (int i = 1; ok && i <= n; i++) {
  for (int j = 1; ok && j <= n; j++) {
   if (grid[i][j] == '.') {
    flood(i, j);
    if (!check()) imp();
    ok = false;
   }
  }
 }
   reset();
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   memset(vis, 0, sizeof vis);
   if (grid[i][j] == '?') {
    if (mustBe(i, j)) {
     mat[i][j] = '.';
     pos.eb(i, j);
    } else mat[i][j] = '#';
   }
  }
 }
  for (auto& u : pos) {
  reset();
  grid[u.fi][u.se] = '#';
  flood(NONE.fi, NONE.se);
  if (check()) amb();
 }
  reset();
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   printf("%c", grid[i][j]);
  }
  printf("\n");
 }
}