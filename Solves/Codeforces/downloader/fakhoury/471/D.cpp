#include <bits/stdc++.h>
using namespace std;
 vector<int> build_Z(vector<int>& s) {
 int n = s.size();
 vector<int> z(n, 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
  if (i <= r)
   z[i] = min(r - i + 1, z[i - l]);
   z[i] = max(1, z[i]);
   while(i + z[i] < n && s[z[i]+i] == s[z[i]])
   z[i]++;
   if (z[i] + i - 1 > r)
   l = i, r = i + z[i] - 1;
 }
  return z;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m; cin >> n >> m;
  vector<int> t(n), p(m);
 for (int i = 0; i < n; i++) cin >> t[i];
 for (int i = 0; i < m; i++) cin >> p[i];
  for (int i = 0, d = t[0], k = 0; i < n; i++) k = t[i], t[i] -= d, d = k;
 for (int i = 0, d = p[0], k = 0; i < m; i++) k = p[i], p[i] -= d, d = k;
  vector<int> s = p;
 s.push_back(-1e9);
 for (int i : t) s.push_back(i);
  vector<int> z = build_Z(s);
  int ans = 0;
 for (int i = m+1; i < n+m+1; i++) {
  if (z[i] == m) ans++;
 }
  cout << ans << '\n';
}