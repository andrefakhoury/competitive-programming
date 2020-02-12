#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 struct UF {
 ll par[MAXN], dif[MAXN];
  inline void init(int n) {
  for (int i = 1; i <= n; i++) {
   par[i] = i;
   dif[i] = 0;
  }
 }
  int find(int x) {
  if (par[x] == x) return x;
  int xx = find(par[x]);
  dif[x] += dif[par[x]];
  return par[x] = xx;
 }
  inline bool same(int u, int v) {
  return find(u) == find(v);
 }
  inline void merge(int u, int v, int w) {
  int a = find(u), b = find(v);
  par[a] = b;
  dif[a] = w - dif[u] + dif[v];
 }
  inline ll solve(int u, int v) {
  return dif[u] - dif[v];
 }
} uf;
 int main() {
 int n, m;
 while(scanf("%d%d", &n, &m), n || m) {
  uf.init(n);
   while(m--) {
   char op; scanf(" %c", &op);
   int u, v; scanf("%d%d", &u, &v);
   if (op == '!') {
    int w; scanf("%d", &w);
    uf.merge(u, v, w);
   } else if (op == '?') {
    if (!uf.same(u, v)) printf("UNKNOWN\n");
    else printf("%lld\n", uf.solve(u, v));
   }
  }
 }
  return 0;
}