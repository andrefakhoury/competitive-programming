#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 ll seg[4 * MAXN];
void update(int p, int i, int j, int k, int v) {
 if (i == j) seg[p] = v;
 else {
  int m = (i + j) / 2;
  if (k <= m) update(p+p, i, m, k, v);
  else update(p+p+1, m+1, j, k, v);
  seg[p] = seg[p+p] + seg[p+p+1];
 }
}
 ll query(int p, int i, int j, int l, int r) {
 if (i >= l && j <= r) return seg[p];
 int m = (i + j) / 2;
 if (r <= m) return query(p+p, i, m, l, r);
 else if (l > m) return query(p+p+1, m+1, j, l, r);
 return query(p+p, i, m, l, r) + query(p+p+1, m+1, j, l, r);
}
 int main() {
 int op, a, b, n, q, T;
 scanf("%d", &T);
 while(T--) {
  scanf("%d%d", &n, &q);
  while(q--) {
   scanf("%d%d%d", &op, &a, &b);
   if (op == 1) update(1, 1, MAXN-1, a, b);
   else printf("%lld\n", query(1, 1, MAXN-1, a, b));
  }
 }
 return 0;
}