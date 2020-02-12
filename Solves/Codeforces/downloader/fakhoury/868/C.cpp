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
 const int MAXN = 1e5 + 5;
 vector<string> vec;
int a[MAXN][5];
int n, k;
 short memo[17][17][17][17][17][17];
 bool solve(int i, int q1, int q2, int q3, int q4, int tot) {
 if (i > n) return tot && (q1*2 <= tot) && (q2*2 <= tot) && (q3*2 <= tot) && (q4*2 <= tot);
 short& ret = memo[i][q1][q2][q3][q4][tot];
 if (~ret) return ret;
  return ret = solve(i+1, q1+a[i][1], q2+a[i][2], q3+a[i][3], q4+a[i][4], tot+1) ||
     solve(i+1, q1, q2, q3, q4, tot);
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 memset(memo, -1, sizeof memo);
  cin >> n >> k;
 for (int i = 1; i <= n; i++) {
  string x;
  for (int j = 1; j <= k; j++) {
   int y; cin >> y;
   x += to_string(y);
  }
  vec.pb(x);
 }
  sort(vec.begin(), vec.end());
 vec.erase(unique(vec.begin(), vec.end()), vec.end());
  n = vec.size();
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < k; j++) {
   a[i+1][j+1] = vec[i][j] == '1';
  }
 }
  bool ans = solve(1, 0, 0, 0, 0, 0);
 cout << (ans ? "YES" : "NO") << '\n';
}