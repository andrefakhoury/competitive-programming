#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
 typedef pair<int, int> pii;
typedef long long ll;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 ll n; cin >> n;
  vector<ll> div = {n};
 for (ll i = 2; i * i <= n; i++) {
  if (n%i == 0) {
   div.eb(i);
   if (i*i != n) div.eb(n/i);
  }
 }
  ll g = 0;
 for (ll x : div) g = __gcd(g, x);
  cout << g << endl;
  return 0;
}