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
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int prox(int k, int n) {
  int lo = k, hi = n, mi;
 while(lo < hi) {
  mi = (lo + hi + 1) / 2;
   if (n/k == n/mi) lo = mi;
  else hi = mi-1;
 }
 return lo+1;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  set<int> all = {0, 1, n};
   // cout << n << ": " << endl;
  for (int k = 1; k <= n; k = prox(k, n)) {
   all.insert(n/k);
  }
   cout << all.size() << "\n";
  for (int i : all) cout << i << ' ';
  cout << endl;
 }
  return 0;
}