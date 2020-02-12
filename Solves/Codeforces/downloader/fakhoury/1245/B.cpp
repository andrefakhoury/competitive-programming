#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
 while(t--) {
  int n; cin >> n;
  int a, b, c; cin >> a >> b >> c;
  string s; cin >> s;
   map<char, int> freq;
  map<char, char> rev;
   freq['R'] = a;
  freq['P'] = b;
  freq['S'] = c;
   rev['R'] = 'P';
  rev['P'] = 'S';
  rev['S'] = 'R';
   string ans;
  for (int i = 0; i < n; i++) ans += 'X';
   for (int i = 0; i < n; i++) {
   if (freq[rev[s[i]]]) {
    ans[i] = rev[s[i]];
    freq[rev[s[i]]]--;
   }
  }
   for (int i = 0; i < n; i++) {
   if (ans[i] == 'X') {
    if (freq['R']) {
     ans[i] = 'R';
     freq['R']--;
    } else if (freq['P']) {
     ans[i] = 'P';
     freq['P']--;
    } else if (freq['S']) {
     ans[i] = 'S';
     freq['S']--;
    }
   }
  }
   int qtt = 0;
  for (int i = 0; i < n; i++) {
   if (rev[s[i]] == ans[i]) qtt++;
  }
   if (qtt >= (n+1)/2) cout << "YES\n" << ans << endl;
  else cout << "NO\n";
 }
  return 0;
}