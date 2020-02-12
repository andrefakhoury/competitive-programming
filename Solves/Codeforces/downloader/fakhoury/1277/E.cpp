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
const int MAXN = 2e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 bool vis[MAXN];
vector<int> edges[MAXN];
ll dfs(int u, int a) {
 vis[u] = true;
  ll ret = 0;
 for (int v : edges[u]) {
  if (v != a && !vis[v]) ret += dfs(v, a);
 }
  return 1 + ret;
}
 void _solve() {
 int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 0; i < m; i++) {
  int u, v; scanf("%d%d", &u, &v);
  edges[u].eb(v);
  edges[v].eb(u);
 }
  memset(vis, 0, sizeof vis);
 ll A = dfs(a, b);
 memset(vis, 0, sizeof vis);
 ll B = dfs(b, a);
  cout << (n - A - 1) * (n - B - 1) << '\n';
 for (int i = 1; i <= n; i++) edges[i].clear();
}
 int main() {
 int T; scanf("%d", &T);
 while(T--) _solve();
 return 0;
}