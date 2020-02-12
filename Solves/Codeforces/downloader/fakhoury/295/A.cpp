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
const int MAXN = 3e5 + 5;
 long long a[MAXN], dif[MAXN];
 struct Query {
 int l, r, d, q;
  Query() {}
  Query(int a, int b, int c) {
  l = a, r = b, d = c;
  q = 0;
 }
};
 vector<int> add1[MAXN];
Query qry[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m, k; cin >> n >> m >> k;
 for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
  int l, r, d; cin >> l >> r >> d;
  qry[i] = Query(l, r, d);
 }
  for (int i = 1; i <= k; i++) {
  int x, y; cin >> x >> y;
  add1[x].pb(y);
 }
  int cur = 0;
 priority_queue<int, vector<int>, greater<int>> pq;
 for (int i = 1; i <= m; i++) {
  for (int x : add1[i]) {
   cur++;
   pq.push(x);
  }
   qry[i].q += cur;
   while(pq.size() && pq.top() == i) {
   pq.pop();
   cur--;
  }
 }
  for (Query& qq : qry) {
  dif[qq.l] += ll(qq.d) * qq.q;
  dif[qq.r+1] -= ll(qq.d) * qq.q;
 }
  long long sum = 0;
 for (int i = 1; i <= n; i++) {
  sum += dif[i];
  a[i] += sum;
 }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
 cout << endl;
}
 