// comi tanto q nao sei mais ler
#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
 map<pii, double> memo;
 // int maxi = 0;
// double solve(int n, int c) {
//     maxi = max(maxi, c);
    //     if (n <= 1) return 1;
//     pii cur = mp(n, c);
 //     if (memo.count(cur)) return memo[cur];
//     return memo[cur] = (1.0 + c) / ((double) c + n) + solve(n-1, c+1);
// }
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
     double ans = n;
    ans = (n + 1) / 2.0;
     cout << fixed << setprecision(7) << ans << endl;
    return 0;
}