#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 const int MAXN = 4e5 + 5;
const int INF = 0x3f3f3f3f;
 #define fi first
#define se second
 int a[MAXN];
int ans[MAXN];
 const int BKS = 555 ;
 int maxi[MAXN];
int mini[MAXN];
 int blk(int ind) {
 return (ind - 1) / BKS;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
  a[i+n] = a[i];
  a[i+2*n] = a[i];
 }
  for (int i = 0; i < BKS; i++) mini[i] = INT_MAX;
  for (int i = 1; i <= 3*n; i++) {
  maxi[blk(i)] = max(maxi[blk(i)], a[i]);
  mini[blk(i)] = min(mini[blk(i)], 2*a[i]);
 }
  ans[3*n] = 1;
 for (int i = 1, l = a[3*n]; i <= 3*n; i++, ans[3*n]++) {
  if (l > 2*a[i]) break;
  l = max(l, a[i]);
 }
  for (int i = 3*n-1; i >= 1; i--) {
  int maior = -1;
   for (int j = i+1; j <= 3*n && blk(j) == blk(i); j++) {
   if (a[j] >= a[i]) {
    maior = j;
    break;
   }
  }
   if (maior == -1) {
   for (int b = blk(i)+1; maior == -1 && b < BKS; b++) {
    if (maxi[b] >= a[i]) {
     for (int j = b * BKS + 1; j <= 3*n && blk(j) == b; j++) {
      if (a[j] >= a[i]) {
       maior = j;
       break;
      }
     }
     }
   }
  }
      int menor = -1;
   for (int j = i+1; j <= 3*n && blk(j) == blk(i); j++) {
   if (2*a[j] < a[i]) {
    menor = j;
    break;
   }
  }
   if (menor == -1) {
   for (int b = blk(i)+1; menor == -1 && b < BKS; b++) {
    if (mini[b] < a[i]) {
     for (int j = b * BKS + 1; j <= 3*n && blk(j) == b; j++) {
      if (2*a[j] < a[i]) {
       menor = j;
       break;
      }
     }
     }
   }
  }
   if (menor == -1 && maior == -1) ans[i] = 3 * n;
  else if (menor == -1 && maior != -1) ans[i] = ans[maior] + maior - i;
  else if (menor != -1 && maior == -1) ans[i] = menor - i;
  else if (menor < maior) ans[i] = menor - i;
  else ans[i] = ans[maior] + maior - i;
 }
  for (int i = 1; i <= n; i++) {
  cout << (ans[i] >= 3*n ? -1 : ans[i]) << " ";
 }
  cout << '\n';
}