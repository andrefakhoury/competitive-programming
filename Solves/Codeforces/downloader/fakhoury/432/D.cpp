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
 int m = s.size();
  s = s + "#" + s;
 int n = s.size();
  vector<int> z = build_Z(s);
  vector<int> freq(m+1, 0), ans;
 for (int i = m+1; i < n; i++) {
  if (z[i] + i == n) ans.push_back(z[i]);
   freq[z[i]]++;
 }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  int sum = n - m - 1;
 for (int i = 0, l = 0; i <= m; i++) {
  if (l < (int)ans.size() && ans[l] == i) {
   cout << ans[l] << " " << sum << "\n";
   l++;
  }
   sum -= freq[i];
 }
 }