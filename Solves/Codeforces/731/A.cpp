#include <bits/stdc++.h>
using namespace std;

int rotleft(char ori, char dest) {
    ori -= "a";
    dest -= "a";
    return (ori-dest+26)%26;
}

int rotright(char ori, char dest) {
    ori -= "a";
    dest -= "a";
    return (dest-ori+26)%26;
}

int main() {
    string s; cin >> s;
    int ans = min(rotleft("a", s[0]), rotright("a", s[0]));
    for (int i = 1; i < s.size(); i++) {
        ans += min(rotleft(s[i-1], s[i]), rotright(s[i-1], s[i]));
    }
    
    cout << ans << endl;
}