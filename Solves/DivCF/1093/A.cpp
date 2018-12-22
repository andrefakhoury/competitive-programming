//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        string s1 = s;
        reverse(s1.begin(), s1.end());
        s != s1 ? cout << s << "\n" : cout << -1 << "\n";
    }
    return 0;
}