#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 const int M = 60;
  int h, m, s, t1, t2;
 cin >> h >> m >> s >> t1 >> t2;
  h = (h * 5) % M;
 m = m % M;
 s = s % M;
 t1 = (t1 * 5) % M;
 t2 = (t2 * 5) % M;
  bool ans = false;
 for (int i = t1;; i = (i + 1) % M) {
  if (i == t2) {
   ans = true;
   break;
  }
   if (i == h) break;
  if (i == m) break;
  if (i == s) break;
 }
  for (int i = t2;; i = (i + 1) % M) {
  if (i == t1) {
   ans = true;
   break;
  }
   if (i == h) break;
  if (i == m) break;
  if (i == s) break;
 }
  cout << (ans ? "YES" : "NO") << '\n';
}