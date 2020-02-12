#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, b, d, ans, c; cin >> n >> b >> d;
 ans = c = 0;
 for (int i = 1; i <= n; i++) {
  int x; cin >> x;
  if (x > b) continue;
  c += x;
  if (c > d) ans++, c = 0; 
 }
 cout << ans << endl;
}