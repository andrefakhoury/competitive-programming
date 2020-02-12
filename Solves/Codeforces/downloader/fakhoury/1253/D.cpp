#include <bits/stdc++.h>
using namespace std;
 #define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 2e5 + 5;
 struct UF {
 int par[MAXN], siz[MAXN], mai[MAXN];
  UF() {
  for (int i = 1; i < MAXN; i++) {
   par[i] = i;
   siz[i] = 1;
   mai[i] = i;
  }
 }
  int find(int x) {
  if (par[x] == x) return x;
  return find(par[x]);
 }
  void merge(int u, int v) {
  int a = find(u), b = find(v);
  if (a == b) return;
   if (siz[a] > siz[b]) swap(a, b);
  par[a] = b;
  siz[b] += siz[a];
  mai[b] = max(mai[a], mai[b]);
 }
  bool same(int u, int v) {
  return find(u) == find(v);
 }
} uf;
 bool vis[MAXN];
int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m; cin >> n >> m;
 for (int i = 0; i < m; i++) {
  int u, v; cin >> u >> v;
  uf.merge(u, v);
 }
  int ans = 0;
 for (int i = 1; i <= n; i++) {
  int root = uf.find(i);
  if (vis[root]) continue;
   for (int j = i; j <= uf.mai[uf.find(i)]; j++) {
   if (uf.same(i, j)) continue;
   ans++;
   uf.merge(i, j);
  }
   vis[root] = true;
 }
  cout << ans << '\n';
  return 0;
}