#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string str; cin >> str;
    
    char last = str[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (str[i] == last) ans++;
        last = str[i];
    }
    cout << ans << endl;
}