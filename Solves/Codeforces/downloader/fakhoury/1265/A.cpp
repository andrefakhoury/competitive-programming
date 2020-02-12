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
 bool can(string& s, size_t i, char c) {
 if (i == 0 && s.size() == 1u) return true;
 if (i == 0) return s[i+1] != c;
 if (i == s.size()-1) return s[i-1] != c;
  return s[i-1] != c && s[i+1] != c;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t; cin >> t;
 while(t--) {
  string s; cin >> s;
  int n = s.size();
   bool imp = false;
  for (int i = 0; i < n-1; i++) {
   if (s[i] == s[i+1] && s[i] != '?')
    imp = true;
  }
   if (imp) {
   cout << -1 << '\n';
   continue;
  }
   for (int i = 0; i < n; i++) {
   if (s[i] != '?') continue;
      bool a = can(s, i, 'a');
   bool b = can(s, i, 'b');
   bool c = can(s, i, 'c');
    if (a) s[i] = 'a';
   else if (b) s[i] = 'b';
   else if (c) s[i] = 'c';
  }
   cout << s << '\n';
 }
  return 0;
}