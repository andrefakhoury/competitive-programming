#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 int const maxn = 5050;
int const inf = 0x3f3f3f3f;
 vector<int> v[maxn];
int dist[maxn];
 int bfs(int x) {
 memset(dist, 0x3f, sizeof(dist));
 dist[x] = 0;
  int ans = 0;
  queue<int> q{{x}};
 while (!q.empty()) {
  int at = q.front();
  q.pop();
    ans = max(ans, dist[at]);
   for (int u : v[at]) {
   if (dist[u] == inf) {
    dist[u] = dist[at] + 1;
    q.push(u);
   }
  }
 }
  return ans;
}
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int n, m, k;
    cin >> n >> m >> k;
     for (int i = 0; i < m; i++) {
     int a, b;
     cin >> a >> b;
      v[a].push_back(b);
     v[b].push_back(a);
    }
  if (n == 1) {
  cout << 0 << "\n";
  return 0;
 }
  int x = 0;
 for (int i = 1; i <= n; i++) x = max(x, bfs(i));
  if (x <= n-k) {
  cout << n << "\n";
  for (int i = 1; i <= n; i++) cout << i << " ";
  cout << "\n";
 }
 else {
  cout << 0 << "\n";
 }
     return 0;
}