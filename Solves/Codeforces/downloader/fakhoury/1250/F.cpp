#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  int ans = 1e8;
 for (int i = 1; i <= n; i++) {
  if (n%i == 0) {
   ans = min(ans, 2*n/i + 2*i);
   }
 }
  cout << ans << endl;
  return 0;
}