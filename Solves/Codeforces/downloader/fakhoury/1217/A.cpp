#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t; cin >> t;
 while(t--) {
  long long a, b, c; cin >> a >> b >> c;
  if (b - c >= a) cout << 0 << '\n';
  else {
   long long lo = 0, hi = c, mi;
   while(lo < hi) {
    mi = (lo + hi + 1) / 2;
    if (a + (c - mi) > b + mi) lo = mi;
    else hi = mi - 1;
   }
    cout << lo + 1 << '\n';
  }
 }
  return 0;
}
 