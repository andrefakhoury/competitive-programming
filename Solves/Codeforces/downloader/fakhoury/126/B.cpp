#include <bits/stdc++.h>
using namespace std;
 vector<int> build_Z(string& s) {
 int n = s.size();
 vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
  if (i <= r)
   z[i] = min(r - i + 1, z[i - l]);
   while(i + z[i] < n && s[z[i]+i] == s[z[i]])
   z[i]++;
   if (z[i] + i - 1 > r)
   l = i, r = i + z[i] - 1;
 }
 return z;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  string s; cin >> s;
 int n = s.size();
  vector<int> z = build_Z(s);
  int m = 0, ans = 0;
 for (int i = 0; i < n; i++) {
  if (z[i] + i == n && z[i] <= m) ans = max(ans, n - i);
  m = max(m, z[i]);
 }
  if (ans) cout << s.substr(0, ans) << "\n";
 else cout << "Just a legend\n";
  return 0;
}