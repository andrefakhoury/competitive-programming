#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 bool _solve() {
 string s; cin >> s;
  map<char, int> f;
 for (char c : s) f[c]++;
  if (f['0'] == 0) return false;
  ll sum = 0;
 for (auto p : f) {
  sum += (p.fi-'0') * p.se;
 }
  if (sum%3) return false;
  ll qtt = 0;
 for (auto p : f) {
  if ((p.fi-'0')%2 ==0 ) {
   qtt += p.se - (p.fi == '0');
  }
 }
  return qtt;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
 while(n--) {
  bool ans = _solve();
  if (ans) cout << "red\n";
  else cout << "cyan\n";
 }
   return 0;
}