#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
 typedef pair<int, int> pii;
typedef long long ll;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 ll T; cin >> T;
 while(T--) {
  int n; cin >> n;
  string s, t; cin >> s >> t;
   vector<pii> ans;
   bool ok = true;
  for (int i = 0; i < n-1; i++) {
   if (s[i] == t[i]) continue;
    int ind1 = -1, ind2 = -1;
   for (int j = i+1; j < n; j++) {
    if (t[j] == t[i]) ind1 = j;
    if (s[j] == t[i]) ind2 = j;
   }
    if (ind1 == -1 && ind2 == -1) {
    ok = false;
    break;
   } else if (ind1 != -1) {
    ans.eb(i+1, ind1+1);
    swap(s[i], t[ind1]);
   } else if (ind2 != -1) {
    ans.eb(ind2+1, i+2);
    swap(s[ind2], t[i+1]);
    ans.eb(i+1, i+2);
    swap(s[i], t[i+1]);
   }
  }
   if (!ok || s != t) cout << "No\n";
  else {
   cout << "Yes\n" << ans.size() << '\n';
   for (auto p: ans) cout << p.fi << ' ' << p.se << '\n';
  }
   }
  return 0;
}