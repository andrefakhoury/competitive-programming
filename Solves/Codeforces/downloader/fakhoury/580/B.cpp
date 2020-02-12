#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
 typedef long long ll;
typedef pair<ll, ll> pll;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  ll n, d; cin >> n >> d;
 vector<pll> a(n);
  for (auto& p : a) cin >> p.fi >> p.se;
 sort(a.begin(), a.end());
  ll ans = 0, cur = 0;
 for (int l = 0, r = 0; r < n; r++) {
  while (a[r].fi - a[l].fi >= d) {
   cur -= a[l].se;
   l++;
  }
   cur += a[r].se;
  ans = max(ans, cur);
 }
  cout << ans << '\n';
}