#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a > b ? a : b)

typedef long long ll;

int main() {
    int n; cin >> n;
    vector<pair<ll, int> > a(n);
    
    for (int i = 0; i < n; i++) {
        int k, x; cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> x;
            a[i].first = max(a[i].first, x);
        }
        a[i].second = k;
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (a[i-1].first - a[i].first) * a[i].second;
        a[i].first = a[i-1].first;
    }
    
    cout << ans << endl;
    return 0;
}