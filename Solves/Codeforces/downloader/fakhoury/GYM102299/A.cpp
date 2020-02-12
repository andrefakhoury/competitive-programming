#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 5e4 + 5, N = 305;
 vector<int> p[N][N], vec[MAXN];
int a[MAXN];
 int main() {
 int n, q; scanf("%d%d", &n, &q);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
  for (int i = 1; i <= n; i++) {
  vec[a[i]].push_back(i);
  for (int j = 1; j < N; j++) {
   p[j][a[i]%j].push_back(i);
  }
 }
  while(q--) {
  int l, r, x, m; // a[i] % m = x
  scanf("%d%d%d%d", &l, &r, &x, &m);
   int ans = 0;
  if (m <= 300) {
   ans = upper_bound(p[m][x].begin(), p[m][x].end(), r) - lower_bound(p[m][x].begin(), p[m][x].end(), l);
  } else {
   for (int i = x; i < MAXN; i += m) {
    ans += upper_bound(vec[i].begin(), vec[i].end(), r) - lower_bound(vec[i].begin(), vec[i].end(), l);
   }
  }
   printf("%d\n", ans);
 }
  }