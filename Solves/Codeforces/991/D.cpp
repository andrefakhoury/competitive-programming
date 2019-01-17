#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f1(char a, char b) {
    if (a == "X" && b == "X") return 0;
    if (a == "0" && b == "X") return 1;
    if (a == "X" && b == "0") return 2;
    if (a == "0" && b == "0") return 3;
}
const int MAXN = 105;
int num[MAXN];

int main() {
    ios::sync_with_stdio(false);
    string a, b; cin >> a >> b;
    
    int ans = 0;
    
    for (int i = 0; i < (int)a.size(); i++) {
        num[i] = f1(a[i], b[i]);
    }
    for (int i = 1; i < (int)a.size(); i++) {
        if ((num[i] == 1 || num[i] == 2 || num[i] == 4) && num[i-1] == 3) { 
            num[i] = 0; ans++;
            continue;
        } else if (num[i] == 3) {
            if (num[i-1] == 1 || num[i-1] == 2 || num[i-1] == 4) {
                num[i] = 0;
                ans++;
            } else if (num[i-1] == 3) {
                num[i] = 4;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    
}