#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
 ll memo[MAXN];
 ll solve(string &s, int i, int n) {
 if (i >= n-1) return 1;
 if (memo[i] != -1) return memo[i];
  bool can = s[i] == 'n' && s[i+1] == 'n';
 can |= s[i] == 'u' && s[i+1] == 'u';
  ll ret = 0;
 if (can) ret += (solve(s, i+2, n)) % MOD;
 return memo[i] = ret + solve(s, i+1, n) % MOD;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  string s; cin >> s;
 int n = s.size();
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < n; i++) {
  if (s[i] == 'm' || s[i] == 'w') {
   cout << 0 << endl;
   return 0;
  }
 }
  cout << solve(s, 0, n)%MOD << endl;
  return 0;
}