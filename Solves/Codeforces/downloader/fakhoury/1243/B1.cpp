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
 int T; cin >> T;
  while(T--)  {
  int n; cin >> n;
  string s, t; cin >> s >> t;
   vector<int> v;
  for (int i = 0; i < n; i++)
   if (s[i] != t[i]) v.eb(i);
   bool ans = false;
   if (v.size() <= 2) for (int i : v) {
   for (int j : v) {
    swap(s[i], t[j]);
    if (s == t) ans = true;
    swap(s[i], t[j]);
   }
  }
   if (ans) cout << "Yes\n";
  else cout << "No\n";
 }
  return 0;
}