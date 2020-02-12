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
const double EPS = 1e-7;
const int MAXN = 2e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  int ans = 0;
 for (int i = 1; i <= n; i++)
  ans += (n - i) > 0 && (n - i) % i == 0;
  cout << ans << '\n';
}