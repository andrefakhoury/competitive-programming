#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 int main() {
 vector<ll> a(3);
 for (auto& x : a) scanf("%lld", &x);
 sort(a.begin(), a.end());
  ll ans = (a[0] + a[1] + a[2]) / 3;
 ans = min(ans, a[0] + a[1]);
 printf("%lld\n", ans);
}