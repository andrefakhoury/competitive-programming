#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
 typedef pair<int, int> pii;
typedef long long ll;
 int dig2(ll x) {
 return 64-__builtin_clzll(x);
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL); 
  ll k, n;
 cin >> k;
  string s;
 cin >> s;
  ll er = max(0ll, (ll)s.size() - dig2(k));
  int c = 0;
 while (er) {
  bool ok = false;
  for (int i = 1; i < (int)s.size(); i++) {
   if (s[i] == '1') {
    s.erase(s.begin()+i);
    c++;
    er--;
    ok = true;
    break;
   }
  }
  if (!ok) break;
 }
  while (er) {
  bool ok =false;
  for (int i = 1; i < (int)s.size(); i++) {
   if (s[i] == '0') {
    s.erase(s.begin()+i);
    c++;
    er--;
    ok = true;
    break;
   }
  }
  if (!ok) break;
 }
  n = stoll(s, 0, 2);
  if (n > k) cout << c+1 << "\n";
 else cout << c << "\n";
}