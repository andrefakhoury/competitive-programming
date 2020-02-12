#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e5 + 5;
 struct Body {
 int r, w;
 Body() {}
 Body(int a, int b) {
  r = a, w = b;
 }
  bool operator<(Body const& bd) const {
  return w == bd.w ? r < bd.r : w < bd.w;
 }
};
 int read() {
 int a, b; scanf("%d.%d", &a, &b);
 return a * 100 + b;
}
 struct ST {
 int st[4 * MAXN], lazy[4 * MAXN];
  ST() {
  memset(st, 0, sizeof st);
  memset(lazy, 0, sizeof lazy);
 }
  void prop(int p, int i, int j) {
  if (lazy[p]) {
   st[p] += lazy[p];
   if (i != j) {
    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
   }
   lazy[p] = 0;
  }
 }
  void update(int p, int i, int j, int l, int r, int x) {
  prop(p, i, j);
  if (i > j || j < l || i > r) return;
   if (i >= l && j <= r) {
   lazy[p] = x;
   prop(p, i, j);
   return;
  }
   int m = (i + j) / 2;
  update(2*p, i, m, l, r, x);
  update(2*p+1, m+1, j, l, r, x);
   st[p] = max(st[2*p], st[2*p+1]);
 }
  void update(int l, int r, int x) {
  update(1, 0, MAXN, l, r, x);
 }
};
 int main() {
 int n, d, ang; scanf("%d%d", &n, &d);
 ang = read();
  vector<Body> vec(2*n);
 for (int i = 0; i < n; i++) {
  int r, w; scanf("%d", &r);
  w = read();
   vec[i] = Body(r, w);
  vec[i+n] = Body(r, w + 36000);
 }
  sort(vec.begin(), vec.end());
  ST seg;
  int ans = 0;
 for (int i = 0, l = 0; i < 2*n; i++) {
  while(vec[l].w + ang < vec[i].w) {
   seg.update(vec[l].r, vec[l].r + d, -1);
   l++;
  }
   seg.update(vec[i].r, vec[i].r + d, 1);
  ans = max(ans, seg.st[1]);
 }
  printf("%d\n", ans);
}