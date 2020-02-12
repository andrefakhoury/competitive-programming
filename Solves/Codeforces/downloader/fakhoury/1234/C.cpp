#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  string s[2];
  cin >> s[0] >> s[1];
   bool vis[200010][2] = {0}, ok = true;
  int when = 1;
   int i, j;
  for (i = 0, j = 0; ok && i < n - 1;) {
   if (vis[i][j]) ok = false;
   vis[i][j] = true;
    if (s[j][i] == '1' || s[j][i] == '2') {
    if (when == 1) i++;
    else ok = false;
     when = 1;
   } else {
    if (when == 1) {
     j = 1 - j;
     when = 2;
    } else {
     when = 1;
     i++;
    }
   }
  }
   // cout << i << ", " << j << ": " << s[j][i] << endl;
  if (i == n-1) {
    if (j == 1) {
    if (s[j][i] != '1' && s[j][i] != '2') {
     ok = false; 
    }
   } else if (s[j][i] == '1' || s[j][i] == '2' || s[1][i] == '1' || s[1][i] == '2') {
    ok = false;
   }
   } else {
   ok = false;
  }
   if (ok) cout << "YES\n";
  else cout << "NO\n";
 }
  return 0;
}