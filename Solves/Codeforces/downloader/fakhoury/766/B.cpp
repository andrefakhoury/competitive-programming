#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e5 + 5;
 int a[MAXN];
int main() {
 int n; scanf("%d", &n);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
  sort(a+1, a+n+1);
  for (int i = 1; i <= n - 2; i++) {
  if (a[i] + a[i+1] > a[i+2]) return !printf("YES\n");
 }
  return !printf("NO\n");
}