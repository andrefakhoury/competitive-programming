#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 inline void _solve() {
 int a, b, c; cin >> a >> b >> c;
 vector<int> v = {a, b, c};
 sort(v.begin(), v.end());
  if (v[2] > v[0] + v[1] + 1) cout << "No\n";
 else cout << "Yes\n";
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve();
  return 0;
}