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
     map<int, int> mp;
    int n; cin >> n;
     int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans += mp[x] != 0;
        mp[x]++;
    }
     cout << ans << endl;
     return 0;
}