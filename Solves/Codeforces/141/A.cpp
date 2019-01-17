#include <bits/stdc++.h>
using namespace std;

int n1[30], n2[30];

int main() {
    ios::sync_with_stdio(false);
    string a, b, c; cin >> a >> b >> c;
    for (int i = 0; i < (int)a.size(); i++) n1[a[i]-"A"]++;
    for (int i = 0; i < (int)b.size(); i++) n1[b[i]-"A"]++;
    for (int i = 0; i < (int)c.size(); i++) n2[c[i]-"A"]++;
    for (int i = 0; i < 30; i++) if (n2[i] != n1[i]) { cout << "NO\n"; return 0; }
    cout << "YES\n"; return 0;
}