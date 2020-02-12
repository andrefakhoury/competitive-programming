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
const int MAXN = 2e5 + 5;
 long long a[MAXN];
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
  int n, k; cin >> n >> k;
 for (int i = 1; i <= n; i++) cin >> a[i];
  long long sum = 0, cur = 0;
 for (int i = 1; i <= k; i++) {
  sum += a[i];
  cur += a[i];
 }
  int ans = 1;
 for (int i = k+1; i <= n; i++) {
  cur -= a[i-k];
  cur += a[i];
   if (cur < sum) {
   sum = cur;
   ans = i - k + 1;
  }
 }
  cout << ans << endl;
}
 