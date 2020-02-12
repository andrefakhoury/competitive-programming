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
const double EPS = 1e-7;
const int MAXN = 2e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
 while(T--) {
  string p, s; cin >> p >> s;
  int n = s.size();
   map<char, int> freq;
  for (char c : p) freq[c]++;
   bool ans = false;
  for (int i = 0; !ans && i < n; i++) {
    map<char, int> f2;
   for (int j = i; !ans && j < n; j++) {
    f2[s[j]]++;
     bool ok = true;
    for (char c = 'a'; c <= 'z'; c++) {
     ok &= freq[c] == f2[c];
    }
     ans = ok;
   }
  }
   cout << (ans ? "YES" : "NO") << '\n';
 }
  return 0; 
}