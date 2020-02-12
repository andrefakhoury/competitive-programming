#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e5 + 5;
 vector<int> edges[MAXN];
char ans[MAXN];
int sz[MAXN];
 int dfs(int u, int p) {
 if (ans[u]) return sz[u] = 0;
  sz[u] = 1;
  for (int v : edges[u]) {
  if (v == p) continue;
  sz[u] += dfs(v, u);
 }
  return sz[u];
}
 int dfs2(int u, int p, int n) {
 if (ans[u]) return -1;
  bool can = n - sz[u] <= n/2;
 for (int v : edges[u]) {
  if (v == p) continue;
  can &= sz[v] <= n/2;
 }
  if (can) return u;
  for (int v : edges[u]) {
  if (v != p) {
   int c = dfs2(v, u, n);
   if (c != -1) return c;
  }
 }
  return -1;
}
 void dfs3(int u, int p, int l) {
 if (ans[u]) return;
 assert(l < 26);
  dfs(u, -1);
 int c = dfs2(u, -1, sz[u]);
  ans[c] = l + 'A';
  for (int v : edges[c])
  if (v != p) dfs3(v, c, l+1);
}
 int main() {
 int n; scanf("%d", &n);
 for (int i = 1; i < n; i++) {
  int u, v; scanf("%d%d", &u, &v);
  edges[u].push_back(v);
  edges[v].push_back(u);
 }
  dfs(1, 0);
 dfs3(dfs2(1, 0, n), -1, 0);
  for (int u = 1; u <= n; u++) printf("%c ", ans[u]);
 printf("\n");
}