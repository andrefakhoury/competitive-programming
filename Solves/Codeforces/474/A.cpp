#include <bits/stdc++.h>
using namespace std;

int main() {
    char dir; cin >> dir;
    string s; cin >> s;
    int m = dir == "R" ? -1 : 1;
    
    string key[3];
    key[0] = "qwertyuiop";
    key[1] = "asdfghjkl;";
    key[2] = "zxcvbnm,./";
    
    for (int i = 0; i < s.size(); i++)
        for (int k = 0; k < 3; k++)
            for (int j = 0; j < key[k].size(); j++)
                if (s[i] == key[k][j]) {
                    s[i] = key[k][min(9, max(j+m, 0))];
                    cout << s[i];
                    break;
                }
}
