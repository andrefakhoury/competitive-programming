#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int m = 0, M = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 97) m++;
        else M++;
    }
    if (M > m) for (int i = 0; i < (int)s.size(); i++) s[i] = (s[i] >= 97) ? s[i]-=32 : s[i];
    else for (int i = 0; i < (int)s.size(); i++) s[i] = (s[i] < 97) ? s[i]+=32 : s[i];
    cout << s << "\n";
    return 0;
}