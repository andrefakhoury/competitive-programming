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
vector<int> edges[MAXN];
 int curTime, t_in[MAXN], t_out[MAXN];
 void dfs(int u) {
 t_in[u] = ++curTime;
 for (int v : edges[u]) dfs(v);
 t_out[u] = ++curTime;
}
 int main() {
 int n, q; scanf("%d%d", &n, &q);
  vector<int> roots;
 for (int u = 0; u < n; u++) {
  int v; scanf("%d", &v);
  if (v == -1) roots.pb(u);
  else edges[v].pb(u);
 }
  for (int u : roots) dfs(u);
  while(q--) {
  int u, v; scanf("%d%d", &u, &v);
  if (t_in[v] <= t_in[u] && t_out[v] >= t_out[u])
   printf("Yes\n");
  else
   printf("No\n");
 }
}