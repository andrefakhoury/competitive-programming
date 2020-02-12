#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5, MAXL = 21;
 struct Edge {
 int u, v, w;
  Edge() {}
  void read() {
  scanf("%d%d%d", &u, &v, &w);
 }
  bool operator<(Edge &e) const {
  return w > e.w;
 }
};
 struct UF {
 int par[MAXN], siz[MAXN];
  void init() {
  for (int i = 0; i < MAXN; i++) {
   par[i] = i;
   siz[i] = 1;
  }
 }
  int find(int x) {
  if (x == par[x]) return x;
  return find(par[x]);
 }
  bool merge(int u, int v) {
  int a = find(u);
  int b = find(v);
  if (a == b) return false;
    if (siz[a] > siz[b]) swap(a, b);
  par[a] = b;
  siz[b] += siz[a];
  return true;
 }
};
 vector<Edge> edg;
 vector<pii> edges[MAXN];
int level[MAXN], par[MAXN][MAXL], ans[MAXN][MAXL];
 void dfs(int u) {
 for (auto e : edges[u]) {
  int v = e.fi, w = e.se;
  if (level[v] == -1) {
   par[v][0] = u;
   ans[v][0] = w;
   level[v] = level[u] + 1;
   dfs(v);
  }
 }
}
 int query(int u, int v) {
 if (level[u] < level[v]) swap(u, v);
  int cur = 0x3f3f3f3f;
 for (int i = MAXL-1; i >= 0; i--) {
  if (level[u] - (1 << i) >= level[v]) {
   cur = min(cur, ans[u][i]);
   u = par[u][i];
  }
 }
  if (u == v) return cur;
  for (int i = MAXL-1; i >= 0; i--) {
  if (par[u][i] != par[v][i]) {
   cur = min(cur, ans[u][i]);
   cur = min(cur, ans[v][i]);
    u = par[u][i];
   v = par[v][i];
  }
 }
  return min(min(cur, ans[u][0]), ans[v][0]);
}
 int main() {
 int n, m, q; scanf("%d%d%d", &n, &m, &q);
 edg.resize(m);
 for (Edge& e : edg) e.read();
  sort(edg.begin(), edg.end());
  UF uf;
 uf.init();
  for (Edge& e : edg) {
  if (uf.merge(e.u, e.v)) {
   edges[e.u].eb(e.v, e.w);
   edges[e.v].eb(e.u, e.w);
  }
 }
  memset(level, -1, sizeof level);
 memset(ans, 0x3f, sizeof ans);
  level[1] = 0;
 dfs(1);
 for (int i = 1; i < MAXL; i++) {
  for (int u = 1; u <= n; u++) {
   ans[u][i] = min(ans[u][i-1], ans[par[u][i-1]][i-1]);
   par[u][i] = par[par[u][i-1]][i-1];
  }
 }
  while(q--) {
  int u, v; scanf("%d%d", &u, &v);
  printf("%d\n", query(u, v));
 }
  return 0; 
}