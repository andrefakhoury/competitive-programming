#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    
    int ans, pw, res;
    ans = res = 0;
    pw = 1;
    
    for (int i = 0; i < m; i++) {
        if (i < n && a[n-i-1] == "1") res = (res+pw)%MOD;
        if (b[m-i-1] == "1") ans = (ans+res)%MOD;
        
        pw = (pw*2)%MOD;
    }
    
    cout << ans << endl;
}