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
 void _solve() {
 int n; cin >> n;
 vector<int> L(n), R(n);
 for (int i = 0; i < n; i++) {
  cin >> L[i];
  L[i] = L[i] == 1 ? 1 : -1;
 }
 reverse(L.begin(), L.end());
  for (int i = 0; i < n; i++) {
  cin >> R[i];
  R[i] = R[i] == 1 ? 1 : -1;
 }
  int sld = 0;
 for (int i = 0; i < n; i++) sld += R[i];
  map<int, int> nec;
  nec[0] = n;
 nec[sld] = 0;
 for (int i = 0; i < n; i++) {
  sld -= R[i];
  if (nec.count(sld)) {
   nec[sld] = min(nec[sld], i+1);
  } else {
   nec[sld] = i+1;
  }
 }
  sld = 0;
 for (int i = 0; i < n; i++) sld += L[i];
  int ans = 2 * n;
 for (int i = 0; i < n; i++) {
  if (nec.count(-sld)) {
   ans = min(ans, nec[-sld] + i);
  }
   sld -= L[i];
   if (nec.count(-sld)) {
   ans = min(ans, nec[-sld] + i + 1);
  }
 }
  cout << ans << '\n';
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
 }