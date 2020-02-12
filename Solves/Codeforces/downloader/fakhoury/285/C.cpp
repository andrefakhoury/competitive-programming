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
const int MAXN = 3e5 + 5;
 long long a[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
 for (int i = 1; i <= n; i++) cin >> a[i];
 sort(a+1, a+n+1);
  long long ans = 0;
 for (int i = 1; i <= n; i++) {
  ans += abs(a[i] - i);
 }
  cout << ans << endl;
}
 