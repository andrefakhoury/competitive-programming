#include <bits/stdc++.h>
 #define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
 using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll m = 0;
    for(int i = 0; i < n; ++i) {
        int a; cin >> a;
        m = max(m, (ll) a);
    }
    for(int i = 0; i < n; ++i) {
        int b; cin >> b;
    }
     ll s = 0;
    int k; cin >> k;
    for(int i = 0; i < k; ++i) {
        int x; cin >> x;
        s += x;
    }
     cout << s + m * k << endl;
}