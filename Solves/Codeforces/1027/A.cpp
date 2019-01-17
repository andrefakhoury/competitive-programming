#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, n; cin >> t;
    bool flag;
    string s;
    while(t--) {
        flag = false;
        cin >> n >> s;
        for (int i = 0, j = n-1; i < j; i++, j--)
            if (abs(s[i]-s[j]) && abs(s[i]-s[j]) != 2) flag = true;
        
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}