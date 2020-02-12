#include <bits/stdc++.h>
using namespace std;
 #define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 void imp() {
 cout << -1 << endl;
 exit(0);
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
 vector<int> a(n);
  for (int& i : a) cin >> i;
  set<int> cur, vis;
  vector<int> ans;
 for (int i = 0; i < n; i++) {
  if (a[i] > 0) {
   if (cur.count(a[i]) || vis.count(a[i])) imp();
   vis.emplace(a[i]);
   cur.emplace(a[i]);
  } else if (a[i] < 0) {
   if (!cur.count(-a[i])) imp();
   cur.erase(-a[i]);
   if (cur.size() == 0) {
    ans.pb(i+1);
    vis.clear();
   }
  }
 }
  if (cur.size()) imp();
  cout << ans.size() << endl;
  int last = 0;
 for (int i : ans) {
  cout << i - last << ' ';
  last = i;
 }
 cout << '\n';
  return 0;
}