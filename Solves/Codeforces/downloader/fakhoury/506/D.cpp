#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e5 + 5;
 int n, m, ans[MAXN];
map<int, vector<int> > edges[MAXN];
map<int, int> vis[MAXN];
unordered_map<int, int> comp[MAXN];
vector<pair<int, int> > queries[MAXN];
map<pair<int, int>, vector<int> > qqq;
vector<int> BIG;
pair<int, int> qq[MAXN];
set<int> colors;
set<int> all[MAXN];
 void dfs(int u, int c, int t, bool isRoot = false) {
 vis[c][u] = t;
 comp[t][u] = 1;
  for (int v : edges[c][u]) if (!vis[c][v]) dfs(v, c, t);
  if (!isRoot) return;
  if (comp[t].size() > 300) BIG.push_back(t);
 else {
  for (auto x : comp[t]) { int v1 = x.first;
   for (auto y : comp[t]) { int v2 = y.first;
    if (v1 >= v2) continue;
     auto cur = qqq[{v1, v2}];
    if (cur.size()) {
     for (int xx : cur) ans[xx]++;
    }
   }
  }
 }
}
 int main() {
 scanf("%d%d", &n, &m);
 for (int i = 1; i <= m; i++) {
  int u, v, w; scanf("%d%d%d", &u, &v, &w);
  edges[w][u].push_back(v);
  edges[w][v].push_back(u);
  all[w].insert(u);
  all[w].insert(v);
  colors.insert(w);
 }
  int q; scanf("%d", &q);
 for (int i = 1; i <= q; i++) {
  int u, v; scanf("%d%d", &u, &v);
  queries[u].emplace_back(v, i);
  qqq[{min(u, v), max(u, v)}].push_back(i);
  qq[i] = {u, v};
 }
  int t = 0;
 for (int c : colors) for (int u : all[c])
  if (!vis[c][u]) dfs(u, c, ++t, true);
  for (int i = 1; i <= q; i++) {
  int u = qq[i].first, v = qq[i].second;
   for (int c : BIG) ans[i] += comp[c][u] && comp[c][v];
  printf("%d\n", ans[i]);
 }
  return 0;
}