#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
 vector<int> edges[MAXN];
int tin[MAXN], low[MAXN], p[MAXN];
vector<int> scc[MAXN];
stack<int> tarj;
bool stackMember[MAXN];
 int curTime = 0, curColor = 0;
 void dfs(int u) {
 tin[u] = low[u] = ++curTime;
 tarj.push(u);
 stackMember[u] = true;
  for (int v : edges[u]) {
  if (!tin[v]) {
   dfs(v);
   low[u] = min(low[u], low[v]);
  } else if (stackMember[v] == true)
   low[u] = min(low[u], tin[v]);
 }
  int w = 0;
 if (low[u] == tin[u]) {
  curColor++;
   while (tarj.top() != u) {
   w = tarj.top();
   scc[curColor].push_back(w);
   stackMember[w] = false;
   tarj.pop();
  }
   w = (int) tarj.top();
  scc[curColor].push_back(w);
  stackMember[w] = false;
  tarj.pop();
 }
}
 int tarjan(int n) {
 for (int i = 1; i <= n; i++)
  if (!tin[i]) dfs(i);
 return curColor;
}
 int main() {
 int n; scanf("%d", &n);
 for (int i = 1; i <= n; i++) scanf("%d", p+i);
  int m; scanf("%d", &m);
 for (int i = 1; i <= m; i++) {
  int u, v; scanf("%d%d", &u, &v);
  edges[u].push_back(v);
 }
  int k = tarjan(n);
  long long ans1 = 0, ans2 = 1;
 for (int i = 1; i <= k; i++) {
  int cur = p[scc[i].back()];
  for (int u : scc[i]) cur = min(cur, p[u]);
  ans1 += cur;
   int qtt = 0;
  for (int u : scc[i]) qtt += p[u] == cur;
  ans2 = (ans2 * qtt) % MOD;
 }
  printf("%lld %lld\n", ans1, ans2);
}