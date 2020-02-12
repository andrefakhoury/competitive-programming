#include <bits/stdc++.h>
using namespace std;
 char s[100005];
int main() {
 scanf(" %s", s);
 int n = strlen(s);
  int ind = 0;
 for (int i = 0; i < n; i++) {
  if (s[i] == '0') {
   ind = i;
   break;
  }
 }
  for (int i = 0; i < n; i++) {
  if (i == ind) continue;
  printf("%c", s[i]);
 }
 printf("\n");
 }