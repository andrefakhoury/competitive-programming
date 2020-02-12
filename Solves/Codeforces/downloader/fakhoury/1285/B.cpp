#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int a[MAXN];
 inline void _solve() {
 int n; cin >> n;
  ll sum = 0, cur = 0, ans = 0;
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
  sum += a[i];
 }
  int qtt = 0, qttAns = 0;
 for (int i = 1; i <= n; i++) {
  if (cur + a[i] > 0) {
   cur += a[i];
   qtt++;
  } else {
   cur = 0;
   qtt = 0;
  }
   if (cur > ans) {
   ans = cur;
   qttAns = qtt;
  }
 }
  if (qttAns == n) ans -= min(a[1], a[n]);
 if (qttAns == 0) ans = *max_element(a+1, a+n+1);
  if (sum > ans) cout << "YES\n";
 else cout << "NO\n";
 }
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
  return 0;
}