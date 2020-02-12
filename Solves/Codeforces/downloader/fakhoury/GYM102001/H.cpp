#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 int ans[MAXN];
 struct Query {
 int l, r, c;
  Query() {}
  void read() {
  scanf("%d%d%d", &l, &r, &c);
 }
  bool operator<(Query const& q) const {
  return r < q.r;
 }
};
 struct BT {
 int bt[MAXN];
  BT() {
  memset(bt, 0, sizeof bt);
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
  int query(int i, int j) {
  return query(j) - query(i-1);
 }
  void update(int i, int val) {
  i++;
  while(i < MAXN) {
   bt[i] += val;
   i += i&-i;
  }
 }
};
 int main() {
 BT bt;
 set<int> st = {0};
  int n, q;
 scanf("%d%d", &n, &q);
 for (int i = 1; i <= n; i++) {
  scanf("%d", ans+i);
  if (ans[i] == 0) {
   ans[i] = -1;
   st.emplace(i);
  }
   bt.update(i, ans[i]);
 }
  vector<Query> qry(q);
 for (auto& p : qry) p.read();
  sort(qry.begin(), qry.end());
 for (Query& q : qry) {
  int cur = bt.query(q.l, q.r);
  if (cur >= q.c) continue;
   vector<int> toErase;
  auto it = st.upper_bound(q.r);
  for (--it; cur < q.c && *it >= q.l; it--) {
   toErase.eb(*it);
    cur += 2;
   ans[*it] = 1;
   bt.update(*it, 2);
  }
   for (int x : toErase) st.erase(x);
  if (cur < q.c) return !printf("Impossible\n");
 }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
 printf("\n");
  return 0;
}