#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
 typedef pair<int, int> pii;
 const int MAXN = 3e5 + 5;
 pii app[MAXN];
 int main() {
 int n, q; scanf("%d%d", &n, &q);
  int cnt = 0;
  vector<pii> pq;
 int last = 0;
  while(q--) {
  int op, x; scanf("%d%d", &op, &x);
   if (op == 1) {
   cnt++;
   app[x].fi++;
   pq.eb(x, app[x].fi);
  } else if (op == 2) {
   cnt -= app[x].fi - app[x].se;
   app[x].se = app[x].fi;
  } else {
   for (int i = last; i < x; i++, last++) {
    int ap = pq[i].fi;
    int qt = pq[i].se;
     if (app[ap].se < qt) {
     cnt--;
     app[ap].se++;
    }
   }
  }
   printf("%d\n", cnt);
 }
}