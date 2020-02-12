#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 const int MAXN = 1e5 + 5;
int a[MAXN];
 int l[MAXN], r[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
 for (int i = 1; i <= n; i++) cin >> a[i];
 a[0] = -100, a[n+1] = 2e9;
  for (int i = 1; i <= n; i++) {
  if (a[i] > a[i-1]) l[i] = l[i-1] + 1;
  else l[i] = 1;
 }
  for (int i = n; i >= 1; i--) {
  if (a[i] < a[i+1]) r[i] = r[i+1] + 1;
  else r[i] = 1;
 }
  int ans = 1;
 for (int i = 1; i <= n; i++) {
  ans = max(ans, l[i-1]+1);
  ans = max(ans, r[i+1]+1);
   if (a[i-1]+1 < a[i+1]) ans = max(ans, l[i-1]+r[i+1]+1);
 }
  cout << ans << endl; 
}