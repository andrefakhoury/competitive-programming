#include <bits/stdc++.h>
using namespace std;
 int main() {
 int n, a, b, k; scanf("%d%d%d%d", &n, &a, &b, &k);
 priority_queue<int, vector<int>, greater<int>> pq;
  int ans = 0;
 for (int i = 1; i <= n; i++) {
  int x; scanf("%d", &x);
  x = (x - 1) % (a + b) + 1;
  pq.emplace((x-1)/a);
 }
  while(pq.size() && pq.top() <= k) {
  k -= pq.top(), ans++;
  pq.pop();
 }
  printf("%d\n", ans);
 return 0;
}