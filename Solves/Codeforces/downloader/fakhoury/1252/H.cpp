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
 const int MAXN = 1e5 + 5;
 pll a[MAXN];
 int main() {
 int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
  scanf("%lld%lld", &a[i].fi, &a[i].se);
  a[i].fi *= 2; a[i].se *= 2;
  if (a[i].fi < a[i].se) swap(a[i].fi, a[i].se);
 }
  sort(a+1, a+n+1);
  ll maxi = 0, ans = 0;
 for (int i = n; i >= 1; i--) {
  ans = max(ans, a[i].fi * a[i].se / 2);
  ans = max(ans, a[i].fi * min(a[i].se, maxi));
  maxi = max(maxi, a[i].se);
 }
  if (ans%4) printf("%lld.5\n", ans/4);
 else printf("%lld.0\n", ans/4);
  return 0;
}