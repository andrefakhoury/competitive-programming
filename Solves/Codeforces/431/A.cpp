#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5]; for (int i = 1; i <= 4; i++) cin >> a[i];
    string s; cin >> s;
    
    int ans = 0;
    for (int i = 0; i < s.size(); i++) ans += a[s[i]-"0"];
    
    cout << ans << endl;
}