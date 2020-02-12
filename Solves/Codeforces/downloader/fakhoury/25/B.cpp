#include <bits/stdc++.h>
using namespace std;
 int main() {
 int n; scanf("%d", &n);
 char s[101];
 scanf(" %s", s);
  int q = 1 + (n%2);
  for (int i = 0; i < n; i++, q--) {
  if (q || i == n-1) printf("%c", s[i]);
  else {
   printf("%c-", s[i]);
   q = 2;
  }
 }
  printf("\n");
}