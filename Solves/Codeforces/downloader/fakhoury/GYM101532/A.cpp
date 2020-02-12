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
int v[MAXN];
int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
     int t; cin >> t;
  while(t--) {
  int n; cin >> n;
   for(int i = 0; i < n; ++i) {
   cin >> v[i];
  }
   ll ans = 0;
  for(int b = 0; b < 22; b -= -1) {
   ll x = (1ll << b);
   for(int l = 0, r; l < n; l = r) {
    r = l;
    while(r < n and ((v[l] >> b)&1) == ((v[r] >> b)&1)) r++;
    if((v[l] >> b)&1) {
     ll tot = r - l;
     tot = tot * (tot + 1)/2;
     ans += tot * x;
    }
   }
  }
   cout << ans << '\n';
 }
  return 0;
}