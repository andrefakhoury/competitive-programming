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
 bool solve(string s, vector<string>& v) {
 bool ret[2] = {0};
  for (auto& x : v) {
  ret[0] |= x[0] == s[1];
  ret[1] |= x[1] == s[0];
 }
  return ret[0] && ret[1];
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 string s; cin >> s;
 int n; cin >> n;
  vector<string> vec(n);
  bool ans = false;
 for (auto& x : vec) {
  cin >> x;
  ans |= x == s;
 }
  ans |= solve(s, vec);
 cout << (ans ? "YES" : "NO") << '\n';
}