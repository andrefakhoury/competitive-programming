#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 long long x, y, a, b; cin >> x >> y >> a >> b;
  long long g = __gcd(a, b);
 a /= g, b /= g;
  int lo = 0, hi = 1e9, mi;
 while(lo < hi) {
  mi = (lo + hi + 1) / 2;
   if (a * mi <= x && b * mi <= y) {
   lo = mi;
  } else {
   hi = mi - 1;
  }
 }
  cout << a * lo << ' ' << b * lo << endl;
}