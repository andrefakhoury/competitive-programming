#include <bits/stdc++.h>
 #define ff first
#define ss second
 using namespace std;
 using ll = long long;
using ii = pair<int, int>;
 const int MAXN = 1e5 + 5;
 int r[MAXN], c[MAXN], sr[MAXN], sc[MAXN];
 int main() {
 ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, q; cin >> n >> q;
 for (int i = 1; i <= n; i++) {
  cin >> c[i];
  c[i] %= 2;
  sc[i] = sc[i-1] + c[i];
 }
  for (int i = 1; i <= n; i++) {
  cin >> r[i];
  r[i] %= 2;
  sr[i] = sr[i-1] + r[i];
 }
  while(q--) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
   int i1 = min(x1, x2);
  int i2 = max(x1, x2);
  int j1 = min(y1, y2);
  int j2 = max(y1, y2);
   int n1 = i2 - i1 + 1;
  int n2 = j2 - j1 + 1;
   int s1 = sc[i2] - sc[i1 - 1];
  int s2 = sr[j2] - sr[j1 - 1];
   if ((s1 == 0 && s2 == 0) || (s1 == n1 && s2 == n2)) {
   cout << "YES\n";
  } else {
   cout << "NO\n";
  }
 }
 }