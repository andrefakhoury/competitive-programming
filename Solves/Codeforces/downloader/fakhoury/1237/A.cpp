#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  queue<pair<int, int>> pos;
  vector<int> ans(n);
  long long sum = 0;
 for (int i = 0; i < n; i++) {
  long long x; cin >> x;
   if (x%2 && x > 0) pos.emplace(i, (x+1)/2);
  if (x%2 && x < 0) pos.emplace(i, (x-1)/2);
   ans[i] = x/2;
  sum += x/2;
 }
  while (sum != 0) {
  int topo = pos.front().first;
   sum -= ans[topo];
  ans[topo] = pos.front().second;
   sum += pos.front().second;
   pos.pop();
 }
  for (int i : ans) cout << i << '\n';
}