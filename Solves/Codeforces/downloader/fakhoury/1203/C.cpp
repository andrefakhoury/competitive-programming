#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 4e5 + 5;
 set<ll> getDiv(ll x) {
 set<ll> ret = {1, x};
  for (ll i = 2; i*i <= x; i++) {
  if (x%i == 0) {
   ret.emplace(i);
   if (i*i != x) ret.emplace(x/i);
  }
 }
  return ret;
}
 int main() {
 int n; scanf("%d", &n);
 vector<ll> a(n);
  for (ll& i : a) scanf("%lld", &i);
 ll g = 0;
 for (ll& i : a) g = __gcd(g, i);
 printf("%ld\n", getDiv(g).size());
}