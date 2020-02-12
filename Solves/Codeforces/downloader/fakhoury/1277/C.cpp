#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 char s1[3] = {'o', 'n', 'e'};
char s2[3] = {'o', 'w', 't'};
 void _solve() {
 set<int> ans;
 string s; cin >> s;
 int n = s.size();
  for (int i = 0; i < n; i++) {
  bool c1 = false, c2 = false;
   bool ok1 = i+2 < n;
  for (int j = 0; ok1 && j < 3 && i+j < n; j++) if (s[i+j] != s1[j]) ok1 = false;
  if (ok1 && i >= 1 && s[i-1] == 'o') {
   ans.emplace(i+1);
   c1 = true;
  }
   bool ok2 = i-2 >= 0;
  for (int j = 0; ok2 && j < 3 && i-j >= 0; j++) if (s[i-j] != s2[j]) ok2 = false;
  if (ok2 && i < n-1 && s[i+1] == 'o') {
   ans.emplace(i-1);
   c2 = true;
  }
   if ((ok1 && !c1) || (ok2 && !c2)) ans.emplace(i);
 }
  cout << ans.size() << '\n';
 for (int i : ans) cout << i+1 << ' ';
 cout << '\n';
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
  return 0;
}