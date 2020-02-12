#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 struct Query {
 ll u, v, w, id;
  Query() {}
  void read(int id) {
  cin >> u >> v >> w;
  u--, v--;
  this->id = id;
 }
  bool operator<(Query const& qq) const {
  return w < qq.w;
 }
};
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
 for (int T = 1; T <= t; T++) {
  int n, q; cin >> n >> q;
   vector<ll> r(n);
  for (ll &i : r) cin >> i;
   vector<pair<int, int> > all;
  for (int i = 0; i < n; i++) {
   all.eb(r[i], i);
  }
   sort(all.begin(), all.end());
   vector<vector<ll> > dist(n, vector<ll>(n));
  for (int i = 0; i < n; i++)
   for (int j = 0; j < n; j++)
    cin >> dist[i][j];
   vector<Query> qry(q);
  for (int i = 0; i < q; i++) qry[i].read(i);
   sort(qry.begin(), qry.end());
   vector<ll> ans(q, -1);
   int last = 0;
   for (int I = 0; I < n; I++) {
   int k = all[I].se;
   int w = all[I].fi;
    while(last < q && qry[last].w < all[I].fi) {
    int u = qry[last].u;
    int v = qry[last].v;
     ans[qry[last].id] = dist[u][v];
    last++;
   }
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
   }
    if (I == n-1 || all[I].fi != all[I+1].fi) {
    while(last < q && qry[last].w <= w) {
     int u = qry[last].u;
     int v = qry[last].v;
      ans[qry[last].id] = dist[u][v];
     last++;
    }
   }
  }
   while(last < q) {
   int u = qry[last].u;
   int v = qry[last].v;
    ans[qry[last].id] = dist[u][v];
   last++;
  }
   cout << "Case #" << T << ":\n";
  for (ll& i : ans) cout << i << '\n';
 }
  return 0;
}