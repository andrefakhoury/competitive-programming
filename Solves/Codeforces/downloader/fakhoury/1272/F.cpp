#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 666;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int n, m;
string s, t;
  struct STT {
 short fi, i, j, sld;
 char se;
  STT() {
  fi = i = j = sld = 0;
  se = 'X';
 }
  STT(int a, int b, int c, int d, char e) {
  fi = a, i = b, j = c, sld = d, se = e;
 }
};
 STT memo[201][201][MAXN+1];
STT solve(int i, int j, int sld) {
 if (i == n && j == m) return {sld, -1, -1, -1, 'X'};
  if (memo[i][j][sld].fi) return memo[i][j][sld];
  int ret = INF, I, J, ni, nj, nsld;
 char op = 'X';
  // (
 if (sld < MAXN) {
  I = i + (i < n && s[i] == '(');
  J = j + (j < m && t[j] == '(');
  ret = 1 + solve(I, J, sld+1).fi;
  op = '(';
   ni = I, nj = J, nsld = sld+1;
 }
  // )
 if (sld) {
  I = i + (i < n && s[i] == ')');
  J = j + (j < m && t[j] == ')');
  int cur = 1 + solve(I, J, sld-1).fi;
  if (cur < ret) {
   ret = cur;
   op = ')';
   ni = I, nj = J, nsld = sld-1;
  }
 }
  return memo[i][j][sld] = {ret, ni, nj, nsld, op};
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 cin >> s >> t;
 n = s.size(), m = t.size();
  solve(0, 0, 0);
 int i = 0, j = 0, sld = 0;
  while(memo[i][j][sld].i != -1 && memo[i][j][sld].se != 'X') {
  cout << memo[i][j][sld].se;
  STT at = memo[i][j][sld];
   i = at.i, j = at.j, sld = at.sld;
 }
  while(sld--) cout << ')';
  // cout << solve(0, 0, 0) << '\n';
  return 0;
}