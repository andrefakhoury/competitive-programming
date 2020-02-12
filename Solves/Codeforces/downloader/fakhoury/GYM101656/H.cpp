#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define ll long long
 typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
 int b[maxn];
 void add(int x, int val) {
    x++;
    for (int i = x; i < maxn; i += i&-i) b[i] += val;
}
 void reset() {
    fill(begin(b), end(b), 0);
}
 int get(int x) {
    x++;
    int ans = 0;
    for (int i = x; i > 0; i -= i&-i) ans += b[i];
    return ans;
}
 int v[maxn];
 int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
     int n;
        while (true) {
        cin >> n;
        if (n == 0) break;
         reset();
         map<string, int> mp;
        int at = 0;
         string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s] = at++;
        }
         for (int i = 0; i < n; i++) {
            cin >> s;
            v[i] = mp[s];
        }
         ll ans = 0;
        for (int i = n-1; i >= 0; i--) {
            ans += get(v[i]);
            add(v[i], 1);
        }
         cout << ans << "\n";
    }
     return 0;
}