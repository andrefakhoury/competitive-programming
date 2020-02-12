#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int const maxm = 1010;
 int dp[2][2*maxm];
 int n, nerr;
string a, b;
  int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
        cin >> a >> b;
     n = a.size();
    int now = 0, old = 1;
     int ans = 0;
    for (int i = 0; i < n; i++) {
        swap(old, now);
         for (int j = max(-i, -1003); j <= 1003 and i+j < n; j++) {
            if (a[i] != b[i+j]) {
                dp[now][j+maxm] = max(dp[now][j+maxm-1], dp[old][j+maxm+1]);
            }
            else {
                dp[now][j+maxm] = dp[old][j+maxm] + 1;
            }
             ans = max(ans, dp[now][j+maxm]);
        }
    }
     if (ans*100 >= 99*n) cout << "Long lost brothers D:\n";
    else cout << "Not brothers :(\n";
     return 0;
}