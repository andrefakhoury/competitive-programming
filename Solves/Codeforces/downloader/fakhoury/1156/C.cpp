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
 const int MAXN = 2e5 + 5;
 int a[MAXN];
int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, z; cin >> n >> z;
  multiset<int> ms;
 for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
 for (int i = (n+1)/2 + 1; i <= n; i++) ms.emplace(a[i]);
  int ans = 0;
 for (int i = 1; i <= (n+1)/2; i++) {
  int u = a[i];
  auto it = ms.lower_bound(u + z);
  if (it != ms.end()) {
   ans++;
   ms.erase(it); 
  }
 }
  cout << ans << '\n';
  return 0;
}