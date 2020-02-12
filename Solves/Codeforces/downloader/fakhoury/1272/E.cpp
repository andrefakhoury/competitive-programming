#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const ll INF = 1e10;
const int MAXN = 2e5 + 5;
 int n, a[MAXN];
int dist[MAXN][2];
 vector<int> edges[MAXN];
void bfs(int p) {
 queue<int> q;
  for (int i = 1; i <= n; i++) if (a[i]%2 == p) {
  q.emplace(i);
  dist[i][p] = 0;
 }
  while(q.size()) {
  int u = q.front();
  q.pop();
   for (int v : edges[u]) {
   if (dist[v][p] == -1) {
    dist[v][p] = dist[u][p] + 1;
    q.emplace(v);
   }
  }
 }
}
 int main() {
 memset(dist, -1, sizeof dist);
  scanf("%d", &n);
 for (int i = 1; i <= n; i++) scanf("%d", a+i);
 for (int i = 1; i <= n; i++) {
  if (i + a[i] <= n) edges[i + a[i]].eb(i);
  if (i - a[i] >= 1) edges[i - a[i]].eb(i);
 }
  for (int i = 0; i <= 1; i++) bfs(i);
 for (int i = 1; i <= n; i++) printf("%d ", dist[i][1-a[i]%2]);
 printf("\n"); 
}