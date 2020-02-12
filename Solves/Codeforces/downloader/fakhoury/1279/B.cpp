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
 inline void _solve() {
 int n;
 ll s;
 cin >> n >> s;
  vector<ll> a(n+1);
 vector<ll> sum(n+1);
  ll ans = 0, qtt = 0;
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
  sum[i] = sum[i-1] + a[i];
   if (sum[i] <= s) qtt = i;
 }
  ll x = 0;
 for (int i = 1; i <= n; i++) {
  // eu pulo a[i];
  auto it = upper_bound(sum.begin()+i+1, sum.end(), s + a[i] + x);
  it--;
   if (*it - a[i] - x <= s) {
   int cur = it - sum.begin();
   if (cur > qtt) {
    qtt = cur;
    ans = i;
   }
    s -= a[i];
   x += a[i];
  }
 }
  cout << ans << '\n';
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
  return 0;
}