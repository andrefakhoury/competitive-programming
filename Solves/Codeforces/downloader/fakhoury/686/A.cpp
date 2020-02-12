#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 long long n, x; cin >> n >> x;
  long long ans = 0;
 while(n--) {
  char op; cin >> op;
  long long k; cin >> k;
   if (op == '+') x += k;
  else {
   if (k <= x) x -= k;
   else ans++;
  }
 }
  cout << x << ' ' << ans << endl;
}