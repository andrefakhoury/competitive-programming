#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e5;
 int ent[MAXN], ext[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  for (int i = 1; i <= n; i++) {
  int x; cin >> x;
  ent[i] = x;
 }
  for (int i = 1; i <= n; i++) {
  int x; cin >> x;
  ext[i] = x;
 }
  set<int> ans;
  queue<int> tun;
 for (int i = 1; i <= n; i++) {
  while(tun.size() && ans.count(tun.front())) tun.pop();
   tun.emplace(ent[i]);
   if (ext[i] != tun.front()) {
   ans.emplace(ext[i]);
  } else {
   tun.pop();
  }
 }
  cout << ans.size() << "\n";
  }