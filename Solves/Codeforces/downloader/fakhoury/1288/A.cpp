#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 inline ll qtt(ll i, ll d) {
 return i + (d + i) / (i + 1);
}
 inline void _solve() {
 ll n, d; cin >> n >> d;
 if (d <= n) {
  cout << "YES\n";
  return;
 }
  bool ans = false;
 for (ll i = 1; i * i <= d; i++) {
  if (qtt(i, d) <= n) ans = true;
  if (qtt(d/i, d) <= n) ans = true;
 }
  if (ans) cout << "YES\n";
 else cout << "NO\n";
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T = 1;
 cin >> T;
 while(T--) _solve();
  return 0;
}