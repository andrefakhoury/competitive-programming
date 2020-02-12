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
 void _solve() {
 int n; scanf("%d", &n);
 vector<int> a(n);
 for (int& i : a) scanf("%d", &i);
  sort(a.rbegin(), a.rend());
  set<int> ok;
 int ans = 0;
 for (int i = 0; i < n; i++) {
  if (a[i] % 2) continue;
   while(!ok.count(a[i]) && a[i] % 2 == 0) {
   ans++;
   ok.emplace(a[i]);
   a[i] /= 2;
  }
 }
  printf("%d\n", ans);
 }
 int main() {
 int T; scanf("%d", &T);
 while(T--) _solve();
  return 0;
}