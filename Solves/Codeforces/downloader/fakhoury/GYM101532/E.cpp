#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
 int f[16][7], m, x;
int n;
map<int, int> cnt;
 void solve(int i, int cur) {
 if (i == m) return void(cnt[cur]++);
  for (int d = 0; d < 6; d++) {
  solve(i+1, (ll(cur) * f[i][d]) % MOD);
 }
}
 int fast_pow(ll a, ll b) {
 ll ans = 1;
  while(b) {
  if(b&1) ans = (ans * a)%MOD;
  b >>= 1;
  a = (a * a)%MOD;
 }
 return ans;
}
 ll solve2(int i, int cur) {
 if (i == n){
  int y = ll(x) * fast_pow(cur, MOD - 2) % MOD;
    return (ll)cnt[y];
 }
  ll sum = 0;
  for (int d = 0; d < 6; d++) {
  sum += solve2(i+1, (ll(cur) * f[i][d]) % MOD);
 }
  return sum;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
     int t; cin >> t;
  while(t--) {
  cin >> n >> x;
   if(n == 1) {
   int ans = 0;
   for(int i = 0; i < 6; ++i) {
    int a; cin >> a;
    ans += a == x;
   }
   cout << ans << '\n';
   continue;
  }
   m = n/2;
  for(int i = 0; i < n; ++i) {
   for(int j = 0; j < 6; ++j) {
    cin >> f[i][j];
   }
  }
   solve(0, 1);
   cout << solve2(m, 1) << "\n";
   cnt.clear();
 }
  return 0;
}