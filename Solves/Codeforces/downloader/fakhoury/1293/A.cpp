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
 int n, s, k; cin >> n >> s >> k;
  vector<int> a(k);
 for (int i = 0; i < k; i++) cin >> a[i];
 sort(a.begin(), a.end());
   int ans = INT_MAX;
 if (!binary_search(a.begin(), a.end(), s)) ans = 0;
 for (int i = 0; i < k; i++) {
  int x = a[i]-1, y = a[i]+1;
  if (x > 0 && !binary_search(a.begin(), a.end(), x))
   ans = min(ans, abs(s - x));
  if (y <= n && !binary_search(a.begin(), a.end(), y))
   ans = min(ans, abs(s - y));
 }
   cout << ans << '\n';
 }
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int T; cin >> T;
 while(T--) _solve(); 
 return 0;
}