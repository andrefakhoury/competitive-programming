#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 150005;
 int mini[MAXN], a[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
 while(t--) {
  int n; cin >> n;
   for (int i = 1; i <= n; i++) cin >> a[i];
   mini[n] = a[n];
  for (int i = n-1; i >= 1; i--) {
   mini[i] = min(a[i], mini[i+1]);
  }
   int ans = 0;
  for (int i = 1; i <= n; i++) {
   ans += mini[i] < a[i];
  }
   cout << ans << '\n';
 }
    return 0;
}