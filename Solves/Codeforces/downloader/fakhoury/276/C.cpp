#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e5 + 5;
 struct BT {
 int bt[MAXN];
  BT() {
  memset(bt, 0, sizeof bt);
 }
  void updt(int i, int val) {
  i++;
   while(i < MAXN) {
   bt[i] += val;
   i += i&-i;
  }
 }
  int query(int i) {
  i++;
   int ret = 0;
  while(i > 0) {
   ret += bt[i];
   i -= i&-i;
  }
   return ret;
 }
  void update(int l, int r) {
  updt(l, 1);
  updt(r+1, -1);
 }
};
 int a[MAXN];
 int main() {
 int n, q; scanf("%d%d", &n, &q);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
  BT bit;
 while(q--) {
  int l, r; scanf("%d%d", &l, &r);
  bit.update(l, r);
 }
  vector<pair<int,int>> freq(n);
 for (int i = 1; i <= n; i++)
  freq[i-1] = {bit.query(i), i};
 sort(freq.rbegin(), freq.rend());
 sort(a+1, a+n+1, greater<int>());
  long long ans = 0;
 for (int i = 0; i < n; i++) {
  ans += (long long)(a[i+1]) * freq[i].first;
 }
  printf("%lld\n", ans);
}