#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    int a[n];
    cin >> a[0];
    
    int ans = 0, cur = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] != a[i-1]) cur++;
        else cur = 1;
        
        ans = max(ans, cur);
    }
    
    ans = max(ans, cur);
    cout << ans << endl;
}