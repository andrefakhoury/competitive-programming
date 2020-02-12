#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
 int a[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  int par = 0, imp = 0;
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
  par += a[i]%2 == 0;
  imp += a[i]%2 == 1;
 }
  int ans = min(par, imp);
  cout << ans << endl;
 return 0;
}