#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e6 + 5, MAXS = 20;
 char s[MAXN];
int memo[1 << MAXS];
 int main() {
 scanf(" %s", s);
 int n = strlen(s);
 for (int i = 0; i < n; i++) {
  int mask = 0;
  for (int j = 0; i + j < n && j < MAXS; j++) {
   int c = s[i+j] - 'a';
   if (mask & (1 << c)) break;
    mask |= 1 << c;
   memo[mask] = __builtin_popcount(mask);
  }
 }
  for (int mask = 0; mask < 1 << MAXS; mask++) {
  for (int b = 0; b < MAXS; b++) {
   if ((mask & (1 << b)) == 0) continue;
   memo[mask] = max(memo[mask], memo[mask ^ (1 << b)]);
  }
 }
  int ans = 1;
 for (int mask = 0; mask < 1 << MAXS; mask++) {
  ans = max(ans, memo[mask] + memo[mask ^ ((1 << MAXS) - 1)]);
 }
  printf("%d\n", ans);
}