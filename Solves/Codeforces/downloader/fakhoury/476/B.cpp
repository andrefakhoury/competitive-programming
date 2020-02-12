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
 double solve(string& s, int i, int x, int xf) {
 if (i == (int)s.size()) return x == xf;
  if (s[i] == '+') return solve(s, i+1, x+1, xf);
 if (s[i] == '-') return solve(s, i+1, x-1, xf);
  return 0.5 * solve(s, i+1, x+1, xf) +
     0.5 * solve(s, i+1, x-1, xf);
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  string a, b; cin >> a >> b;
 vector<int> ini, fim;
  int f = 0;
 for (char c : a) f += c == '+' ? 1 : -1;
  cout << setprecision(12) << fixed << solve(b, 0, 0, f) << endl;
 return 0;
}
 