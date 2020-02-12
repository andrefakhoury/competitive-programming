#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 2e5 + 5;
 // <qtd, total>
pii qtd[MAXN];
int a[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(nullptr);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
  cin >> a[i];
   qtd[a[i]].fi++;
  if (qtd[a[i]].fi >= k) {
   cout << 0 << endl;
   return 0;
  }
 }
  int x = 0, ans = 0x3f3f3f3f;
 while(true) {
  x++;
   bool ok = true;
  for (int i = 1; i <= n; i++) {
   if (a[i] == 0) continue;
   ok = false;
    a[i] /= 2;
    qtd[a[i]].fi++;
   qtd[a[i]].se += x;
    if (qtd[a[i]].fi >= k) ans = min(ans, qtd[a[i]].se);
  }
   if (ok) break;
 }
  cout << ans << endl;
   return 0;
}