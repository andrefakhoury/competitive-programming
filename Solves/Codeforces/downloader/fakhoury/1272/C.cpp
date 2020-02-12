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
 bool can[MAXN];
 ll get(ll n) {
 return n*(n+1)/2;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, k; cin >> n >> k;
 string s; cin >> s;
  for (int i = 0; i < k; i++) {
  char c; cin >> c;
  can[c] = true;
 }
  ll ans = 0;
 int l = 0;
 for (int i = 0; i < n; i++) {
  if (!can[s[i]]) {
   ans += get(i - l);
   l = i+1;
  }
 }
 ans += get(n-l);
  cout << ans << '\n';
 return 0;
}