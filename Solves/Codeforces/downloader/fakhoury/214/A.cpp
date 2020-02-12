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
const int MAXN = 1e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, m; cin >> n >> m;
 int ans = 0;
 for (int i = 0; i <= 1000; i++) {
  for (int j = 0; j <= 1000; j++) {
   ans += (i*i+j == n) && (i+j*j == m);
  }
 }
  cout << ans << endl;
   return 0;
}
 