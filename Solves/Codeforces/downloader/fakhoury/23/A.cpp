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
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 string s; cin >> s;
 int n = s.size(), ans = 0;
 for (int i = 0; i < n-1; i++) for (int j = i; j < n; j++)
  if (s.substr(i+1, n-i).find(s.substr(i, j - i + 1)) != string::npos)
   ans = max(ans, j - i + 1);
  cout << ans << '\n';
 return 0;
}