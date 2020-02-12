#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
 typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 const int N = 19;
 ll cond[N][N], memo[N][1 << N], a[N];
int n, m;
 ll solve(int i, int mask) {
 mask |= 1 << i;
  ll& ret = memo[i][mask];
 if (~ret) return ret;
  if (__builtin_popcount(mask) == m) return ret = a[i];
  ret = 0;
 for (int j = 0; j < n; j++) {
  if (mask & (1 << j)) continue;
  ret = max(ret, a[i] + cond[i][j] + solve(j, mask));
 }
  return ret;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 memset(memo, -1, sizeof memo);
  int k; cin >> n >> m >> k;
 for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
  int x, y, c; cin >> x >> y >> c;
  cond[x-1][y-1] = c;
 }
  ll ans = 0;
 for (int i = 0; i < n; i++) ans = max(ans, solve(i, 0));
  cout << ans << '\n';
}