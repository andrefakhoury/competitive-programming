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
const int MAXN = 1e5 + 5;
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
        int t;
    cin >> t;
     while (t--) {
        int x;
        cin >> x;
                if (x <= 2) cout << 0 << "\n";
        else cout << x - (x+1)/3 << "\n";
    }
     return 0;
}