#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 #define int long long
 typedef long long ll;
typedef pair<int, int> pii;
 const int maxn = 15;
const int INF = 0x3f3f3f3f;
 ll dist[maxn][maxn];
int n;
ll L;
 vector<ll> v[1<<maxn][maxn];
 bool brute(int mask, ll cur, int ini, int atual) {
 if (mask == (1 << n) - 1) {
  return (cur + dist[atual][ini]) == L;
 }
  for (int i = 0; i < n; i++) {
  if (mask & (1 << i)) continue;
  if (brute(mask | (1 << i), cur + dist[atual][i], ini, i))
   return true;
 }
  return false;
}
 bool bruteForce() {
 for (int i = 0; i < n; i++)
  if (brute(1 << i, 0, i, i)) return true;
 return false;
}
 void calc(int at, int resta, int mask = 0, int val = 0) {
 if (resta == 0) {
  v[mask][at].push_back(val);
  // cout << val << " ";
  // cout << __builtin_popcount(mask) << "\n";
  return;
 }
  for (int i = 0; i < n; i++) {
  if ((mask&(1<<i)) == 0) {
   calc(i, resta-1, mask|(1<<i), val + dist[at][i]);
  }
 }
}
 int32_t main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> L;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> dist[i][j];
  bool ans;
 if (n <= 1) ans = bruteForce();
 else {
  int n1 = n/2;
  int n2 = n-n1;
   calc(0, n1, 1);
  if (n1 != n2) calc(0, n2, 1);
   for (int i = 0; i < (1<<n); i++) 
   for (int j = 0; j < n; j++)
    sort(v[i][j].begin(), v[i][j].end());
   for (int i = 0; i < (1<<n); i++) {
   for (int j = 0; j < n; j++) {
    for (int val : v[i][j]) {
     if (binary_search(v[((1<<n)-1-i)|1|(1<<j)][j].begin(),
                    v[((1<<n)-1-i)|1|(1<<j)][j].end(),
                    L - val)) {
      cout << "possible\n";
      return 0;
     }
    }
   }
  }
  cout << "impossible\n";
  return 0;
 }
  if (ans) cout << "possible\n";
 else cout << "impossible\n";
  return 0;
}