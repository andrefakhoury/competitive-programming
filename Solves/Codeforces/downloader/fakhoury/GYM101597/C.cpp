#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int t;
    cin >> t;
     while (t--) {
     ll n;
     cin >> n;
      if (n%3 != 0 and n%4 != 0) {
      cout << "IMPOSSIBLE\n";
     }
     else if (n%3 == 0) {
      cout << n/3 << " " << n/3 << " " << n/3 << "\n";
     }
     else {
      cout << n/2 << " " << n/4 << " " << n/4 << "\n";
     }
    }
     return 0;
}