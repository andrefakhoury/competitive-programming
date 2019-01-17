#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string a, b; cin >> a >> b;
    
    for (int i = 0; i < (int)a.size(); i++) a[i] = tolower(a[i]);
    for (int i = 0; i < (int)b.size(); i++) b[i] = tolower(b[i]);
    
    if (a < b) return !printf("-1\n");
    else if (a > b) return !printf("1\n");
    else return !printf("0\n");
}