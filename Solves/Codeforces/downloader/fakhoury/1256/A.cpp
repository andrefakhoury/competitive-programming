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
 int main() {
 int t; scanf("%d", &t);
  while(t--) {
  ll a, b, n, s; scanf("%lld%lld%lld%lld", &a, &b, &n, &s);
   ll qtt = s / n;
  s -= min(a * n, qtt * n);
   if (s <= b) printf("YES\n");
  else printf("NO\n");
 }
  return 0;
}