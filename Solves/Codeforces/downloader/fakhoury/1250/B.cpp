#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 int const maxn = 505050;
int const maxk = 8080;
ll const inf = 0x3f3f3f3f3f3f3f3f;
 int cnt[maxk];
 ll f(ll k, ll block_size) {
 ll ans = 0;
  int l = 1, r = k;
  while (l <= r) {
  if (l == r) l++, ans++;
  else if (cnt[l] + cnt[r] <= block_size) l++, r--, ans++;
  else l++, ans++;
 }
  return ans;
}
 ll g(ll k, ll ld, ll res) {
 int l = 2*ld, r = ld-1;
 while (l-r > 1) {
  int m = (l+r+1)/2;
   if (f(k, m) <= res) l = m;
  else r = m;
 }
 if (f(k, l) == res) return l*res;
 else return inf;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, k;
 cin >> n >> k;
  for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
   cnt[x]++;
 }
  sort(cnt+1, cnt+k+1, greater<int>{});
  int gr = *max_element(cnt+1, cnt+k+1);
 ll ans = inf;
  for (int i = (k+1)/2; i <= k; i++) {
  ans = min(ans, g(k, gr, i));
 }
  cout << ans << "\n";
 return 0;
}