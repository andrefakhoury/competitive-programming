// Example program
#include <bits/stdc++.h>

using namespace std;

char seat[10001][5];

int main()
{
    int n;
    cin >> n;
    string ans = "NO";
    
    for (int i = 0; i < n; i++) {
        cin >> seat[i][0];
        cin >> seat[i][1];
        cin >> seat[i][2];
        cin >> seat[i][3];
        cin >> seat[i][4];
    }
    
    for (int i = 0; i < n; i++) {
        if (seat[i][0] == seat[i][1] && seat[i][0] == "O") {
            seat[i][0] = "+";
            seat[i][1] = "+";
            ans = "YES";
            break;
        } 
        if (seat[i][3] == seat[i][4] && seat[i][3] == "O") {
            seat[i][3] = "+";
            seat[i][4] = "+";
            ans = "YES";
            break;
        }
    }
    
    if (ans == "NO") cout << ans << endl;
    if (ans == "YES") {
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
        cout << seat[i][0];
        cout << seat[i][1];
        cout << seat[i][2];
        cout << seat[i][3];
        cout << seat[i][4] << endl;
    }
    }
}
