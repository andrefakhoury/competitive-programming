#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 1e3 + 5;
 char mat[MAXN][MAXN];
int ini1[MAXN][MAXN], fim1[MAXN][MAXN];
int ini2[MAXN][MAXN], fim2[MAXN][MAXN];
 struct Star {
 int x, y, r;
 Star() {}
 Star(int a, int b, int c) {
  x = a, y = b, r = c;
 }
};
 int main() {
 int n, m; scanf("%d%d", &n, &m);
 for (int i = 1; i <= n; i++) 
  for (int j = 1; j <= m; j++)
   scanf(" %c", &mat[i][j]);
  vector<int> row1[MAXN]; // all '.' on each col
 vector<int> row2[MAXN]; // all '.' on each col - reversed
 vector<int> col1[MAXN]; // all '.' on each row
 vector<int> col2[MAXN]; // all '.' on each row - reversed
  for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) if (mat[i][j] == '.') row1[i].eb(j);
  for (int j = m; j >= 1; j--) if (mat[i][j] == '.') row2[i].eb(-j);
 }
  for (int j = 1; j <= m; j++) {
  for (int i = 1; i <= n; i++) if (mat[i][j] == '.') col1[j].eb(i);
  for (int i = n; i >= 1; i--) if (mat[i][j] == '.') col2[j].eb(-i);
 }
  vector<Star> ans;
  for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   if (mat[i][j] == '.') continue;
    auto it1 = lower_bound(row1[i].begin(), row1[i].end(), j);
   auto it2 = lower_bound(row2[i].begin(), row2[i].end(), -j - 1);
   auto it3 = lower_bound(col1[j].begin(), col1[j].end(), i);
   auto it4 = lower_bound(col2[j].begin(), col2[j].end(), -i - 1);
    int r = min({i-1, j-1, n-i, m-j});
   if (it1 != row1[i].end()) r = min(r, (*it1) - j - 1);
   if (it2 != row2[i].end()) r = min(r, j + (*it2) - 1);
   if (it3 != col1[j].end()) r = min(r, (*it3) - i - 1);
   if (it4 != col2[j].end()) r = min(r, i + (*it4) - 1);
    if (r > 0) {
    ans.eb(i, j, r);
     ini1[i][j-r]++;
    fim1[i][j+r]++;
    ini2[i-r][j]++;
    fim2[i+r][j]++;
   }
  }
 }
  for (int i = 1; i <= n; i++) {
  for (int j = 1, qtt = 0; j <= m; j++) {
   qtt += ini1[i][j];
   if (mat[i][j] == '*' && qtt) mat[i][j] = '.';
   qtt -= fim1[i][j];
  }
 }
  for (int j = 1; j <= m; j++) {
  for (int i = 1, qtt = 0; i <= n; i++) {
   qtt += ini2[i][j];
   if (mat[i][j] == '*' && qtt) mat[i][j] = '.';
   qtt -= fim2[i][j];
  }
 }
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
  if (mat[i][j] == '*') return !printf("-1\n");
  printf("%ld\n", ans.size());
 for (auto S : ans) {
  printf("%d %d %d\n", S.x, S.y, S.r);
 }
}