#include <bits/stdc++.h>
using namespace std;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, t, k, d; cin >> n >> t >> k >> d;
  int old = t * ((n + k - 1) / k);
 int nov = 0;
  for (int o = 1, n1 = t, n2, i = 1, made = 0; made < n; i++, nov++) {
  n1--;
  if (n1 == 0) {
   made += k;
   n1 = t;
  }
   if (o == 2) {
   n2--;
   if (n2 == 0) {
    made += k;
    n2 = t;
   }
  }
   if (i == d) {
   o++;
   n2 = t;
  }
 }
  if (nov < old) cout << "YES\n";
 else cout << "NO\n";
}