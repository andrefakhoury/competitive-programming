#include <bits/stdc++.h>
using namespace std;
 #define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 2e5 + 5;
 ll a[MAXN], sum[MAXN], ans[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n, m; cin >> n >> m;
 for (int i = 1; i <= n; i++) cin >> a[i];
 sort(a+1, a+n+1);
  for (int i = 1; i <= n; i++) {
  ans[i] = ans[i-1] + a[i] + sum[i];
  sum[i+m] += a[i] + sum[i];
 }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
 cout << '\n';
    return 0;
}