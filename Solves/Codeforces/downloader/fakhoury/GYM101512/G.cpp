#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define MAX
   int main() { 
 fastcin;
     int t; cin >> t;
    while(t--) {
        int n; cin >> n;
         long long a, b, c; cin >> a >> b >> c;
        a = -a;
         double cur = - (1.*b*b - 4. * a * c) / (4.0 * a);
        int ans = 1;
         for (int i = 2; i <= n; i++) {
            cin >> a >> b >> c;
            a = -a;
            double x = - (1.0*b*b - 4.0 * a * c) / (4.0 * a);
             if (x > cur) {
                cur = x;
                ans = i;
            }
        }
         cout << ans << '\n';
    }
}